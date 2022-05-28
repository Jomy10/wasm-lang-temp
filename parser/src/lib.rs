// Parser
pub use tree_sitter::{Node, Parser, Tree};
pub use tree_sitter_wasm_lang::language;

// Scopes
use std::collections::HashMap;

#[derive(PartialEq, Debug)]
pub struct Scope<'a> {
    pub id: usize,
    pub scope_name: &'a str,
    pub vars: HashMap<String, usize>,
    pub superscope: Option<usize>,
}

impl<'a> Scope<'a> {
    pub fn new(id: usize, scope_name: &'a str) -> Self {
        Self {
            id,
            scope_name,
            vars: HashMap::new(),
            superscope: None,
        }
    }
}

pub fn get_scopes<'a>(tree: &Tree, source: &'a str) -> HashMap<usize, Scope<'a>> {
    let mut scope_table: HashMap<usize, Scope> = HashMap::new();

    let root = tree.root_node();

    parse_node(&root, source, &mut scope_table, 0);
    
    return scope_table;
}

const GLOBAL_SCOPE_NAME: &'static str = "global";

fn parse_node<'a>(
    node: &Node, 
    source: &'a str, 
    scope_table: &mut HashMap<usize, Scope<'a>>,
    current_scope: usize,
) {
    if node.has_error()  { panic!("Error: {:?}", node) }
    if node.is_missing() { panic!("Missing node: {:?}", node) }
    
    match node.kind() {
        // =================================
        // Nodes that change the scope
        // =================================
        "program" => {
            let child_count = node.child_count();
            
            let global_scope = Scope::new(node.id(), GLOBAL_SCOPE_NAME);
            if scope_table.insert(node.id(), global_scope).is_some() {
                panic!("Unexpectedly found global scope twice. This is a bug in th compiler.");
            }
            
            let mut i = 0;
            while i < child_count {
                parse_node(&node.child(i).unwrap(), source, scope_table, node.id());
                i += 1;
            }
        }
        "func_decl" => {
            let name = node.child_by_field_name("name").unwrap();
            let name = &source[name.range().start_byte..name.range().end_byte];
            let mut scope = Scope::new(node.id(), name);
            scope.superscope = Some(current_scope);
            
            if scope_table.insert(node.id(), scope).is_some() {
                panic!("Unexpectedly found same scope twice. This is a bug in the compiler.");
            }
            
            if let Some(params) = node.child_by_field_name("params") {
                println!("Parsing params");
                parse_node(&params, source, scope_table, node.id());
            }
            
            if let Some(body) = node.child_by_field_name("body") {
                parse_node(&body, source, scope_table, node.id());
            }
        }

        // =================================
        // Nodes that don't change the scope
        // =================================
        "body" => {
            let child_count = node.child_count();
            
            let mut i = 0;
            while i < child_count {
                parse_node(&node.child(i).unwrap(), source, scope_table, current_scope);
                
                i += 1;
            }
        }
        "params_decl" => {
            let child_count = node.child_count();
            
            let mut i = 0;
            while i < child_count {
                parse_node(&node.child(i).unwrap(), source, scope_table, current_scope);
                
                i += 1;
            }
        }
        // =================================
        // Nodes that insert new variables
        // =================================
        "param_decl" => {
            let name = node.child_by_field_name("name").unwrap();
            let name = &source[name.range().start_byte..name.range().end_byte];
            
            scope_table
                .get_mut(&current_scope)
                .unwrap()
                .vars
                .insert(name.to_string(), node.id());
        }
        "var_decl" => {
            let name = node.child_by_field_name("name").unwrap();
            let name = &source[name.range().start_byte..name.range().end_byte];
            
            scope_table
                .get_mut(&current_scope)
                .unwrap()
                .vars
                .insert(name.to_string(), node.id());
        }
        
        // =================================
        // Unhandled tokens
        // =================================
        "return" | "type" | "int_literal" | "ident" | "pub"  => {}
        
        _ => {
            panic!("Unhandled node {}", node.kind());
        }
    }
}
