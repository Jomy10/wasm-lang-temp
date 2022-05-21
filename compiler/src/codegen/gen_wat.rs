use parser::parser::{Node, FuncParam, Type, LiteralValue};
use concat_string::concat_string;

/// Generate wat code from nodes
pub fn generate_wat(nodes: &Vec<Node>) -> String {
    let mut gen_source: Vec<String> = Vec::new();

    let mut nodes_iter = nodes.iter();
    while let Some(node) = nodes_iter.next() {
        gen_source.push(gen_node(&node));
    }
    return gen_source.join("")
}

/// Generate wat code for a node
fn gen_node(node: &Node) -> String {
    match node {
        Node::Func { ext_name, int_name, public, body, params } => {
            Function{ 
                external_name: ext_name.to_string(), 
                internal_name: int_name.to_string(), 
                is_public: *public,
                params: params.to_vec(),
                body,
            }.build()
        }
        Node::VarDecl { ext_name: _, int_name, t: ty, initial_value } => {
            if let Some(initial_value) = initial_value {
                VarAssign{
                    int_name,
                    ty,
                    value: gen_node(initial_value),
                }.build()
            } else {
                "".to_string()
            }
        }
        Node::Literal(literalVal) => {
            match literalVal {
                LiteralValue::i32(v) => {
                    format!("i32.const {v}")
                }
                LiteralValue::i64(v) => {
                    format!("i64.const {v}")
                }
                LiteralValue::f32(v) => {
                    format!("f32.const {v}")
                }
                LiteralValue::f64(v) => {
                    format!("f64.const {v}")
                }
            }
        }
    }
}

/// Return all variable declarations in a vector of nodes
fn var_declarations<'a>(nodes: &'a Vec<Node>) -> Vec<&'a Node<'a>> {
    let mut decls: Vec<&Node> = Vec::new();
    nodes.iter().for_each(|node| {
        match node {
            Node::VarDecl { .. } => {
                decls.push(node);
            }
            _ => {}
        }
    });
    
    return decls;
}

/// Buildable to wat
trait Buildable {
    fn build(&self) -> String;
}


/// Represents a function in wat
struct Function<'a> {
    external_name: String,
    internal_name: String,
    is_public: bool,
    params: Vec<FuncParam<'a>>,
    body: &'a Vec<Node<'a>>,
}

impl Buildable for Function<'_> {
    fn build(&self) -> String {        
        // Build function
        let int_name = &self.internal_name;
        let export = if self.is_public {
            let mut exp = format!("(export \"{}\" (func ${}))", self.external_name, self.internal_name);
            if &self.external_name == "main" {
                exp = concat_string!(
                    exp,
                    format!("(export \"_start\" (func ${}))", self.internal_name)
                );
            }
            exp
        } else { "".to_string() };
        let params: String = self.params.iter().map(|param| {
            format!("(param ${} {})", param.int_name, param.t)
        }).collect::<Vec<String>>().join("");
        let body = generate_wat(self.body);
        let var_decls = var_declarations(self.body); // TODO: threads for body and var_decls?
        let locals = var_decls.iter().map(|decl| {
            if let Node::VarDecl { ext_name: _, int_name, t, initial_value: _ } = decl {
                format!( "(local ${int_name} {t})" )
            } else {
                unreachable!()
            }
        }).collect::<Vec<String>>().join("");
        
        format!(
            "{export}(func ${int_name} {params}{locals} {body})"
        )
    }
}

/// `var a = a`
struct VarAssign<'a> {
    int_name: &'a str,
    ty: &'a Type,
    value: String,
}

impl Buildable for VarAssign<'_> {
    fn build(&self) -> String {
        let value = &self.value;
        let int_name = self.int_name;
        
        format!(
            "{value} local.set ${int_name}"
        )
    }
}
