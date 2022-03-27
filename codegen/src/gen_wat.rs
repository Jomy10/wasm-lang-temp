use lexer::tokenize;
use parser::{Node, parse};

// Every node outside of function will be put in a `_start` function

/// Generate `wat` source code from a source file
pub fn generate_wat(source: &str) -> String {
    let tokens = tokenize(&source);
    let parsed = parse(&tokens, &source);
    
    let mut functions: Vec<FunctionBuilder> = Vec::new();
    
    let mut main_func = FunctionBuilder::new("_start".to_string(), Vec::new(), None, true);
    
    parsed.iter().for_each(|node| {
        for instr in parse_node(&node) {
            main_func.append_instr(instr);
        }
    });
    
    functions.push(main_func);
    
    let mut code = String::new();
    code.push_str("(module\n");
    for func in functions {
        code.push_str(&func.build());
    }
    code.push_str(")");
    
    code
}

#[allow(unused_assignments)]
fn gen_store_let(name: &Box<Node>, ty: &Box<Node>, value: &Box<Node>) -> String {
    // the type that represents the the type in wasm
    let mut wat_type = String::new();
    match ty.get_type_str().unwrap().as_str() {
        "i32" => wat_type = "i32".to_string(),
        _ => unimplemented!()
    }
    format!(
        "{wat_type}.const {}\nlocal.store ${}",
        &*value.get_literal_value().unwrap(),
        &*name.get_ident_name().unwrap()
    )
}

fn parse_node(node: &Node) -> Vec<Instruction> {
    match node {
        Node::DocComment(_) | Node::Comment(_) => vec![Instruction::Ignore],
        Node::Import(_) => unimplemented!(),
        Node::Let { name, ty, value } => {
            vec![
                Instruction::AddLocal(format!("(local ${} {})", name.get_ident_name().unwrap(), ty.get_type_str().unwrap())),
                Instruction::AddInstruction(gen_store_let(name, ty, value))
            ]
        }
        Node::TypeI32 => todo!(),
        Node::TypeI64 => {todo!()}
        Node::TypeF32 => {todo!()}
        Node::TypeF64 => {todo!()}
        Node::TypeString => {todo!()}
        Node::TypeArray(_) => {todo!()}
        Node::StringLiteral(_) => {todo!()}
        Node::Int32Val(_) => {todo!()}
        Node::Int64Val(_) => {todo!()}
        Node::Ident(_) => {todo!()}
        Node::AtDecl(_) => {todo!()}
        Node::AtDeclWithParams(_, _) => {todo!()}
        Node::ParamCall { .. } => {todo!()}
        Node::__None => {unreachable!()}
    }
}

enum Instruction {
    /// Add an instruction (one line)
    AddInstruction(String),
    /// Add a local to the functin
    AddLocal(String),
    Ignore
}

struct FunctionBuilder {
    name: String,
    params: Vec<String>,
    /// Return type
    ret: Option<String>,
    locals: Vec<String>,
    instrs: Vec<String>,
    public: bool
}

impl FunctionBuilder {
    pub fn new(name: String, params: Vec<String>, ret: Option<String>, public: bool) -> Self {
        Self { name, params, ret, locals: Vec::new(), instrs: Vec::new(), public }
    }
    
    pub fn append_instr(&mut self, instruction: Instruction) {
        match instruction {
            Instruction::AddInstruction(instr) => {self.instrs.push(instr)}
            Instruction::AddLocal(val) => {self.locals.push(val)}
            Instruction::Ignore => {}
        }
    }
    
    pub fn build(&self) -> String {
        let name = &self.name;
        let params = &self.params.join(" ");
        let ret = match self.ret.clone() { Some(val) => val, None => String::new() };
        let locals = &self.locals.join(" ");
        let instrs = &self.instrs.join(" ");
        let export = if self.public { format!("(export \"{}\" (func ${}))\n", self.name, self.name) } else { String::new() };
        format!(
            "{export}(func ${name}
                {params}
                {ret}
                {locals}

                {instrs}
            )"
        )
    }
}