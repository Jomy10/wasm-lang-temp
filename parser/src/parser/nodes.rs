use std::fmt::Display;

#[derive(Debug, PartialEq)]
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
    FuncParam 
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

#[derive(Debug, PartialEq, Clone)]
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