use crate::parser::Node;
use std::{
    rc::Rc,
    collections::HashMap,
    cell::{RefCell, Ref},
};

#[derive(Debug, Clone, Eq, PartialEq)]
pub struct Scope {
    pub name: String,
    /// Variables: `(Variable outside name, inside name)`
    pub vars: HashMap<String, String>,
    /// The scopes this scope is a subscope of
    pub superscope: Option<String>,
}

impl Scope {
    pub fn new(name: &str) -> Self {
        Self { name: name.to_string(), vars: HashMap::new(), superscope: None }
    }
}

pub struct PostParser {
    scopes: RefCell<HashMap<String, Scope>>
}

impl PostParser {
    pub fn new() -> Self {
        Self { scopes: RefCell::new(HashMap::new()) }
    }
    
    pub fn scopes(&self) -> Ref<HashMap<String, Scope>> {
        return self.scopes.borrow();
    }
    
    /// Edits parsed nodes in place
    pub fn post_parse(&self, nodes: &mut Vec<Node>) {
        let global_scope: Scope = Scope::new("global");
        self.scopes.borrow_mut().insert("global".to_string(), global_scope);
        self.post_parse_nodes(nodes, "global");
    }
    
    fn post_parse_nodes(&self, nodes: &mut Vec<Node>, current_scope: &str) {
        for node in nodes.iter_mut() {
            self.post_parse_node(node, current_scope)
        }
    }
    
    fn post_parse_node(&self, node: &mut Node, current_scope: &str) {
        match node {
            Node::Func { ext_name: _, int_name, public: _, params: _, body } => {
                let mut new_scope = Scope::new(int_name);
                new_scope.superscope = Some(self.scopes.borrow().get(current_scope).unwrap().name.clone());
                self.scopes.borrow_mut().insert(int_name.to_string(), new_scope);
                self.post_parse_nodes(body, int_name);
            }
            Node::VarDecl { ext_name, int_name, t: _, initial_value: _ } => {
                if let Some(scope) = self.scopes.borrow_mut().get_mut(current_scope) {
                    scope.vars.insert(ext_name.to_string(), int_name.to_string());
                } else {
                    panic!("Invalid scope")
                }
            }
            Node::Variable { name, function: _, int_name } => {
                let scopes_ptr = self.scopes.as_ptr(); 
                if let Some(current_scope) = unsafe { (*scopes_ptr).get(current_scope) } {
                    let var_decl = self.get_var_int_name(name, current_scope);
                    if var_decl.is_none() { panic!("Variable {name} is not declared in scope {}.", current_scope.name) }
                    *int_name = var_decl; // Always some
                }
                drop(scopes_ptr);
            }
            Node::Literal(_) => {}
            Node::Return(node) => {
                if let Some(node) = node.as_mut() {
                    let node = Rc::get_mut(node).unwrap();
                    self.post_parse_node(node, current_scope);
                }
            }
        }
    }
 
    /// Get the internal name of a variable  
    fn get_var_int_name(&self, name: &str, current_scope: &Scope) -> Option<String> {
        if let Some(variable) = current_scope.vars.get(name) {
            return Some(variable.to_string());
        } else {
            if let Some(superscope) = &current_scope.superscope {
                if let Some(superscope) = self.scopes.borrow().get(superscope) {
                    let name = self.get_var_int_name(name, superscope);
                    if name.is_some() {
                        return name;
                    }
                }
            }
            return None;
        }
    }
}
