use tree_sitter::{Node, Tree};
use concat_string::concat_string;
use std::collections::HashMap;

#[derive(Debug, PartialEq)]
struct Scope {
    pub id: usize,
    pub vars: HashMap<String, usize>,
    pub superscope: Option<usize>
}

impl Scope {
    pub fn new(id: usize) -> Self {
        Self {
            id,
            vars: HashMap::new(),
            superscope: None,
        }
    }
}

/// Represents generated source code returned by `gen_node`
struct Source {
    /// Source code that should be inserted at the current position
    pub source: Option<String>,
    /// Source code that should be inserted at the top of a function
    pub top_source: Option<String>,
}

#[allow(unused)]
impl Source {
    /// New source code at current position
    pub fn new(source: String) -> Self {
        Self { source: Some(source), top_source: None }
    }
    
    pub fn new_mixed(source: String, top: String) -> Self {
        Self { source: Some(source), top_source: Some(top) }
    }
    
    pub fn new_top(top: String) -> Self {
        Self { source: None, top_source: Some(top) }
    }
    
    pub unsafe fn unwrap_source_unchecked(&self) -> &str {
        &self.source.as_ref().unwrap_unchecked()
    }
    
    pub unsafe fn unwrap_unchecked(&self) -> (&str, &str) {
        (
            &self.source.as_ref().unwrap_unchecked(),
            &self.top_source.as_ref().unwrap_unchecked()
        )
    }
    
    pub unsafe fn unwrap_top_unchecked(&self) -> &str {
        &self.top_source.as_ref().unwrap_unchecked()
    }
    
    pub fn sources(&self) -> (&Option<String>, &Option<String>) {
        (
            &self.source,
            &self.top_source
        )
    }
}

#[derive(Debug, PartialEq, Eq, Hash, Clone, Copy)]
enum MetaTag {
    /// Indicates that the following nodes will be used to assign to a variable of this type
    // TODO: rename to eval type, because this is used for anything that should return a value (e.g. return statements, var decl, ...)
    VarDeclType,
    FuncReturnType,
    GenMod
}

/// Generate wat code from nodes
pub fn generate_wat(tree: &Tree, source: &str, gen_mod: bool) -> String {
    let mut scope_table: HashMap<usize, Scope> = HashMap::new();
    
    let meta = if gen_mod {
        Some(HashMap::from([(MetaTag::GenMod, String::from("true"))]))
    } else {
        None
    };
    
    gen_node(&tree.root_node(), source, &mut scope_table, 0, &meta).source.unwrap()
}

/// Generate wat code for a node
fn gen_node(
    node: &Node,
    source: &str,
    scope_table: &mut HashMap<usize, Scope>,
    current_scope: usize,
    meta: &Option<HashMap<MetaTag, String>>,
) -> Source {
    match node.kind() {
        "program" => {
            // Change scope
            let global_scope = Scope::new(node.id());
            if scope_table.insert(node.id(), global_scope).is_some() {
                panic!("Unexpectedly found global scope twice. This is a bug in th compiler.");
            }
            
            // Generate source for children
            let child_count = node.child_count();
            
            let mut i = 0;
            let mut generated_source: Vec<String> = Vec::new();
            while i < child_count {
                generated_source.push(gen_node(&node.child(i).unwrap(), source, scope_table, node.id(), meta).source.unwrap());
                i += 1;
            }
            
            if let Some(meta) = meta.as_ref() {
                if let Some(add_mod) = meta.get(&MetaTag::GenMod) {
                    if add_mod == "true" {
                        return Source::new(concat_string!("(module ", generated_source.join(" "), ")"));
                    }
                }
            }
            
            return Source::new(generated_source.join(" "));
        }
        "func_decl" => {
            // Change scope
            let mut scope = Scope::new(node.id());
            scope.superscope = Some(current_scope);
            
            if scope_table.insert(node.id(), scope).is_some() {
                panic!("Unexpectedly found same scope twice. This is a bug in the compiler.");
            }
            
            // Func name
            let name = node.child_by_field_name("name").unwrap();
            let name = &source[name.range().start_byte..name.range().end_byte];
            
            // Params
            let params = if let Some(params_node) = node.child_by_field_name("params") {
                unsafe { gen_node(&params_node, source, scope_table, node.id(), meta).unwrap_top_unchecked().to_string() }
            } else {
                String::new()
            };
            
            // Return type
            let ty: &str;
            let result = if let Some(return_type) = node.child_by_field_name("return_type") {
                ty = &source[return_type.range().start_byte..return_type.range().end_byte];
                format!("(result {})", type_to_wat(ty))
            } else {
                ty = "";
                "".to_string()
            };
            
            // Add return type to metadata for parsing children
            let mut new_meta = meta.clone().unwrap_or(HashMap::<MetaTag, String>::new());
            new_meta.insert(MetaTag::FuncReturnType, ty.to_string());
            
            // Parse body
            let body: String;
            let locals: String;
            if let Some(body_node) = node.child_by_field_name("body") {
                let srcs = gen_node(&body_node, source, scope_table, node.id(), &Some(new_meta));
                let (source, _locals) = unsafe { srcs.unwrap_unchecked() };
                locals = _locals.to_string();
                body = source.to_string();
            } else {
                locals = String::new(); body = String::new();
            }
            
            // generate internal name
            let int_name = if name == "main" {
                "main".to_string()
            } else {
                concat_string!(node.id().to_string(), "$", name)
            };
            
            // export public function
            let mut export = if node.child_by_field_name("pub").is_some() {
                format!("(export \"{}\" (func ${}))", name, int_name)
            } else {
                "".to_string()
            };
            
            // add extra export for main function
            if name == "main" {
                // Add _start to export
                export.push_str("(export \"_start\" (func $main))")
            }
            
            Source::new(format!("{export}(func ${int_name} {params}{result}{locals} {body} )"))
        }
        "body" => {
            // Generate source for children
            let child_count = node.child_count();
            let mut gen_source: Vec<String> = Vec::new();
            let mut locals: Vec<String> = Vec::new();
            let mut i = 0;
            while i < child_count {
                let srcs = gen_node(&node.child(i).unwrap(), source, scope_table, current_scope, meta);
                let (source, local) = srcs.sources();
                if let Some(source) = source { gen_source.push(source.to_string()) }
                if let Some(local) = local { locals.push(local.to_string()) }
                i += 1;
            }
            
            Source { 
                source: Some(gen_source.join(" ")),
                top_source: Some(locals.join(""))
            }
        }
        "params_decl" => { 
            // Generate source for params
            let child_count = node.child_count();
            let mut gen_source: Vec<String> = Vec::new();
            let mut i = 0;
            while i < child_count {
                let srcs = gen_node(&node.child(i).unwrap(), source, scope_table, current_scope, meta);
                gen_source.push(unsafe { srcs.unwrap_top_unchecked() }.to_string());
                i += 1;
            }
            
            Source::new_top(gen_source.join(""))
        }
        "param_decl" => {
            let name = node.child_by_field_name("name").unwrap();
            let name = &source[name.range().start_byte..name.range().end_byte];
            let int_name = format!("{}${}", node.id(), name);
            let ty = node.child_by_field_name("type").unwrap();
            let ty = &source[ty.range().start_byte..ty.range().end_byte];
            if ty == "Void" { panic!("Found void type in parameter {}", name) }
            let ty = type_to_wat(ty);
            
            Source::new_top(format!("(param ${int_name} {ty})"))
        }
        "var_decl" => {
            let name = node.child_by_field_name("name").unwrap();
            let name = &source[name.range().start_byte..name.range().end_byte];
            
            let int_name = concat_string!(node.id().to_string(), "$", name.to_string());
            
            let ty = if let Some(ty_node) = node.child_by_field_name("type") {
                let ty = &source[ty_node.range().start_byte..ty_node.range().end_byte];
                if ty == "Void" { panic!("Found void type for variable {}", name) }
                type_to_wat(ty)
            } else {
                let val = node.child_by_field_name("value").expect(&format!("Couldn't infer type for {}", name));
                match val.kind() {
                    "int_literal" => String::from("i32"),
                    _ => panic!("Couldn't infer type for {}", name)
                }
            };

            // Generate assignment source code
            let mut new_meta = meta.clone().unwrap_or(HashMap::<MetaTag, String>::new());
            new_meta.insert(MetaTag::VarDeclType, ty.clone());
            
            let source_node = node.child_by_field_name("value").unwrap();
            let generated_source = gen_node(&source_node, source, scope_table, current_scope, &Some(new_meta));
            let (assign_source, locals) = generated_source.sources();
            let mut extra_locals = "";
            if let Some(locals) = locals {
                extra_locals = locals;
            }
            let assign_source = if let Some(src) = assign_source {
                format!("{src} local.set ${int_name}")
            } else {
                String::new()
            };
    
            scope_table
                .get_mut(&current_scope)
                .unwrap()
                .vars
                .insert(name.to_string(), node.id());
            
            Source::new_mixed(
                assign_source,
                format!("(local ${} {}){extra_locals}", int_name, ty),
            )
        }
        "return" => {
            return if let Some(source_node) = node.child_by_field_name("value") {
                // Check if a value is being returned, or it is an empty return stmt
                let ty = meta.as_ref().unwrap().get(&MetaTag::FuncReturnType).unwrap();
                if ty == "" {
                    panic!("No return type declared for this function, but a value is returned");
                }
                
                // Value should return ty
                let mut new_meta = meta.clone().unwrap_or(HashMap::<MetaTag, String>::new());
                new_meta.insert(MetaTag::VarDeclType, ty.clone());
                
                // generate the source that should be returned
                let generated_source = gen_node(&source_node, source, scope_table, current_scope, &Some(new_meta));
                let (return_source, locals) = generated_source.sources();
                
                // Extra locals that might be created
                let mut extra_locals = "";
                if let Some(locals) = locals {
                    extra_locals = locals;
                }
    
                let return_source = if let Some(src) = return_source {
                    format!("{src} return")
                } else {
                    panic!("Expected a return value of type {ty}, but got Void")
                };
                
                Source::new_mixed(return_source, extra_locals.to_string())
            } else {
                if let Some(ty) = meta.as_ref().unwrap().get(&MetaTag::FuncReturnType) {
                    if ty != "" {
                        panic!("Expected a return value of type {ty}, but got Void")
                    }
                }
                Source::new("return".to_string())
            };
        }
        "int_literal" => {
            let int = &source[node.range().start_byte..node.range().end_byte];
            let ty = meta.as_ref().unwrap().get(&MetaTag::VarDeclType).unwrap();
            Source::new(format!("{}.const {}", ty, int))
        }
        "ident" => {
            if meta.as_ref().unwrap().get(&MetaTag::VarDeclType).is_some() {
                // Ident should be used to return a value
                let name = &source[node.range().start_byte..node.range().end_byte];
                let id = scope_table.get(&current_scope).unwrap().vars.get(name).expect(&format!("Variable {name} not found"));
                
                Source::new(format!("local.get {}", concat_string!("$", id.to_string(), "$", name)))
            } else {
                panic!("Unexpected/Unhandeled ident")
            }
        }
        "binary_expr" => {
            let lhs = node.child(0).unwrap();
            let op = node.child(1).unwrap();
            let rhs = node.child(2).unwrap();

            let src = &source[op.range().start_byte..op.range().end_byte];
            
            let ty = meta.as_ref().unwrap().get(&MetaTag::VarDeclType).unwrap();
            
            let l = gen_node(&lhs, source, scope_table, current_scope, meta);
            let r = gen_node(&rhs, source, scope_table, current_scope, meta);
            let (l_code, l_locals) = l.sources();
            let (r_code, r_locals) = r.sources();
            let l_code = l_code.as_ref().unwrap();
            let r_code = r_code.as_ref().unwrap();
            let l_locals: &str = l_locals.as_ref().map(|s| s.as_str()).unwrap_or("");
            let r_locals: &str = r_locals.as_ref().map(|s| s.as_str()).unwrap_or("");
            
            match src {
                "*" => Source::new_mixed(
                    format!("{} {} {}.mul", l_code, r_code, ty),
                    concat_string!(l_locals, r_locals),
                ),
                "/" => {
                    let div = if ty == "i32" {
                        "div_s"
                    } else { // f
                        "div"
                    };
                    
                    Source::new_mixed(
                        format!("{} {} {}.{}", l_code, r_code, ty, div),
                        concat_string!(l_locals, r_locals),
                    )
                },
                "+" => Source::new_mixed(
                    format!("{} {} {}.add", l_code, r_code, ty),
                    concat_string!(l_locals, r_locals),
                ),
                "-" => Source::new_mixed(
                    format!("{} {} {}.sub", l_code, r_code, ty),
                    concat_string!(l_locals, r_locals),
                ),
                _ => panic!("Unknown binary operator {}", src)
            }
        }
        "unary_expr" => {
            let op = node.child(0).unwrap();
            let rhs = node.child(1).unwrap();

            let src = &source[op.range().start_byte..op.range().end_byte];
            
            let ty = meta.as_ref().unwrap().get(&MetaTag::VarDeclType).unwrap();
            
            let r = gen_node(&rhs, source, scope_table, current_scope, meta);
            let (r_code, r_locals) = r.sources();
            let r_code = r_code.as_ref().unwrap();
            let r_locals: &str = r_locals.as_ref().map(|s| s.as_str()).unwrap_or("");
            
            match src {
                "-" => Source::new_mixed(
                    format!("{}.const -1 {} {}.mul", ty, r_code, ty),
                    r_locals.to_string(),
                ),
                _ => panic!("Unknwon unary operator")
            }
        }
        _ => panic!("Unhandled node: {} - {:?}", node.kind(), node)
    }
}

fn type_to_wat(ty: &str) -> String {
    match ty {
        "i32" | "i64" | "f32" | "f64" => { return ty.to_string() }
        "Void" => { return String::new() }
        _ => panic!("Unexpected type {ty}")
    }
}
