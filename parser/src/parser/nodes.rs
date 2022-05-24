use std::{fmt::Display, rc::Rc};

#[derive(Debug, PartialEq, Clone)]
pub enum Node<'a> {
    Func { 
        /// External name
        ext_name: &'a str, 
        /// Internal name (wat)
        int_name: String,
        /// Wheter the function is public
        public: bool,
        /// The function parameters
        params: Vec<FuncParam<'a>>, 
        /// Function body
        body: Vec<Node<'a>>
    },
    /// Mutable variable declaration with `var`
    VarDecl {
        ext_name: &'a str,
        int_name: String,
        /// Variable's type
        t: Type,
        // Initial value can be a constant or a function or any other statement
        initial_value: Option<Rc<Node<'a>>>
    },
    /// A variable ident.
    Variable {
        name: &'a str,
        function: String,
        /// Will always hold a value after post parse
        int_name: Option<String>,
    },
    Literal(LiteralValue<'a>),
    /// A return statement with an optional return value
    Return(Option<Rc<Node<'a>>>)
}

#[allow(non_camel_case_types)]
#[derive(Debug, PartialEq, Clone)]
pub enum LiteralValue<'a> {
    i32(&'a str),
    i64(&'a str),
    f32(&'a str),
    f64(&'a str)
}

impl<'a> LiteralValue<'a> {
    pub fn new(value: &'a str, t: Type) -> Self {
        match t {
            Type::i32 => Self::i32(value),
            Type::i64 => todo!(),
            Type::f32 => todo!(),
            Type::f64 => todo!(),
        }
    }
}

#[derive(Debug, PartialEq, Clone)]
pub struct FuncParam<'a> {
    /// The name it is referred to in the source code
    pub refer_name: &'a str,
    /// The name it is referred to in the generated code
    pub int_name: String,
    /// The parameter's type
    pub t: Type
}

#[derive(Debug, PartialEq, Clone, Copy)]
#[allow(non_camel_case_types)]
pub enum Type {
    i32,
    i64,
    f32,
    f64
}

impl Type {
    pub fn from(str: &str) -> Self {
        match str {
            "i32" => Type::i32,
            _ => unimplemented!("Unimplemented type {}", str)
        }
    }
}

impl Display for Type {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", match self {
            Self::i32 => "i32",
            Self::i64 => "i64",
            Self::f32 => "f32",
            Self::f64 => "f64",
        })
    }
}
