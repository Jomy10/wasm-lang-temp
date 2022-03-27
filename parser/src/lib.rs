use lexer::*;

/// Parse source code to abstract syntax tree
pub fn parse<'a>(tokens: &'a Vec<Token>, source: &'a str) -> Vec<Node<'a>> {
    let mut tokens = tokens.iter();
    
    let mut tree: Vec<Node> = Vec::new();
    while let Some(token) = tokens.next() {
       tree.push(parse_token(&token, &source, &mut tokens))
    }
   
    tree
}

fn parse_doc_comment<'a>(token: &'a Token, source: &'a str) -> Node<'a> {
    Node::DocComment(&source[token.range.0..token.range.1]) // TODO: parse,
}
fn parse_import<'a>(token: &'a Token, source: &'a str, token_iter: &mut std::slice::Iter<'a, lexer::Token>) -> Node<'a> {
    Node::Import(Box::new(parse_token(expect_token(&token_iter.next().expect(&format!("Expected a module or file after `import` at {},{}", token.range.0, token.range.1)), vec!["ident", "string"]).expect(&format!("Expected a module or file after `import` at {},{}", token.range.0, token.range.1)), &source, token_iter)))
}

/// Parse a type declaration (e.g. `: i32` or `: Array<i32>`)
fn parse_type<'a>(token: &'a Token, source: &'a str, token_iter: &mut std::slice::Iter<'a, lexer::Token>) -> Node<'a> {
    parse_token(
        expect_token(
            token,
            vec!["t_i32", "t_i64", "t_f32", "t_f64", "t_string", "t_array", "array"]
        ).expect(&format!("Expected a type after `:` at {}, {}", token.range.0, token.range.1)),
        &source, token_iter)
}

/// `let <name>: [type] = <value>`
fn parse_let<'a>(token: &'a Token, source: &'a str, token_iter: &mut std::slice::Iter<'a, lexer::Token>) -> Node<'a> {
    let name = parse_token(
        expect_token(&token_iter.next().expect(&format!("Expected a name for let at {},{}", token.range.0, token.range.1)), vec!["ident"]).expect(&format!("Expected a name for let at {},{}", token.range.0, token.range.1)),
        &source, token_iter);
    let mut ty: Node = Node::__None;
    match expect_token(&token_iter.next().expect(&format!("Expected `=` or type after value name at {},{}", token.range.0, token.range.1)), vec!["equal", "type_decl"]) {
        Ok(token) => {
            if token.name == "type_decl" {
                // further parsing
                ty = parse_type(
                    &token_iter.next().expect(&format!("Expected a type after `:` at {}, {}", token.range.0, token.range.1)),
                    source,
                    token_iter
                );
                let _ = expect_token(&token_iter.next().expect(&format!("expected `=` in let declaration at {},{}", token.range.0, token.range.1)), vec!["equal"]);
            } else {
                // pass "equal"
            }
        }, Err(err) => panic!("{}", err)
    }
    
    let ty_str= ty.get_type_str().unwrap_or_default();
    
    let value = parse_literal(
        expect_token(
            &token_iter.next().expect(&format!("Expected a value for let at {},{}", token.range.0, token.range.1)),
            vec!["int", "floating_point", "string", "array"]
        ).expect(&format!("Expected a value for let at {},{}", token.range.0, token.range.1)),
        &source,
        if ty == Node::__None { None } else { Some(ty_str.as_str()) });
    
    // Derive type
    if ty == Node::__None {
        match value {
            // TODO: other types
            Node::StringLiteral(_) => ty = Node::TypeString,
            Node::Int32Val(_) => ty = Node::TypeI32,
            Node::Int64Val(_) => ty = Node::TypeI64,
            _ => panic!("Could not derive type for let {} at {},{}\nHELP: indicate type using `: <type>`", name.get_ident_name().unwrap(), token.range.0, token.range.1)
        }
    } else {
        // type check
        match value {
            Node::StringLiteral(_) => if ty != Node::TypeString {panic!("Should be string literal")},
            Node::Int32Val(_) => if ty != Node::TypeI32 {panic!("Should be i32 val")},
            Node::Int64Val(_) => if ty != Node::TypeI64 {panic!("Should be i32 val")},
            _ => unimplemented!()
        }
    }
    
    
    Node::Let {
        name: Box::from(name),
        ty: Box::from(ty),
        value: Box::from(value),
    }
}

/// Parse a string literal, integer, etc.
/// - `ty`: specify a type if necessary (e.g. `i32` and `i64` for integers)
fn parse_literal<'a, 'b>(token: &'b Token, source: &'a str, ty: Option<&str>) -> Node<'a> {
    match token.name.as_str() {
        "int" => {
            let int_val_str = &source[token.range.0..token.range.1];
            if let Some(ty) = ty {
                match ty {
                    "i32" => Node::Int32Val(int_val_str.parse::<i32>().expect(&format!("'{}' is not a valid 32-bit integer", int_val_str))),
                    "i64" => Node::Int64Val(int_val_str.parse::<i64>().expect(&format!("'{}' is not a valid 64-bit integer", int_val_str))),
                    _ => unreachable!()
                }
            } else {
                Node::Int32Val(int_val_str.parse::<i32>().expect(&format!("'{}' is not a valid 32-bit integer", int_val_str)))
            }
        },
        "string" => Node::StringLiteral(&source[token.range.0..token.range.1]),
        _ => unimplemented!("Token {} is not implemented", token.name)
    }
}

fn parse_at_decl_with_params<'a>(token: &'a Token, source: &'a str) -> Node<'a> {
    let pos = (source.find("(").unwrap(), source.find(")").unwrap());
    let name = &source[token.range.0+1..pos.0];
    let inside = &source[pos.0+1..pos.1];
    Node::AtDeclWithParams(
        name,
        parse_func_args(&inside)
    )
}

/// Parse function arguments in function calls and @decl
fn parse_func_args(inside: &str) -> Vec<Box<Node>> {
    let mut indices: Vec<usize> = vec![0];
    inside.chars().enumerate().for_each(|(idx, c)| if c == ',' { indices.push(idx) });
    indices.push(inside.len());
    
    (1..indices.len()).into_iter().map(|i| {
        let arg: &str = &inside[indices[i-1]..indices[i]];
        if let Some(index_of_colon) = arg.find(":") {
            // Named param
            let arg2: &str = &arg[index_of_colon+1..arg.len()];
            Box::from(Node::ParamCall {
                name: &arg[0..index_of_colon],
                value: Box::new(parse_literal(&tokenize(&arg2)[0], &arg2, None))
            })
        } else {
            // param
            println!("inside token: {:?}", tokenize(&arg)[0]);
            Box::from(parse_literal(&tokenize(&arg)[0], &arg, None))
        }
    }).collect::<Vec<Box<Node>>>()
}

#[cfg(test)]
#[test]
fn parse_args_test() {
    let source = r#"param: 5, "string_arg""#;
    let args = parse_func_args(source);
    let expected = vec![
        Node::ParamCall { name: "param", value: Box::new(Node::Int32Val(5)) },
        Node::StringLiteral("string_arg")
    ];
    let args: Vec<Node> = args.into_iter().map(|s| *s).collect();
    assert_eq!(expected, args)
}

/// Parse a single `Token` into a `Node`
fn parse_token<'a>(token: &'a Token, source: &'a str, token_iter: &mut std::slice::Iter<'a, lexer::Token>) -> Node<'a> {
    println!("Token: {:?}", token);
    match token.name.as_str() {
        "doc_comment" => parse_doc_comment(token, source),
        "comment" => Node::Comment(&source[token.range.0..token.range.1]),
        "import" => parse_import(token, source, token_iter),
        "let" => parse_let(token, source, token_iter),
        "ident" => Node::Ident(&source[token.range.0..token.range.1]),
        "string" => Node::StringLiteral(&source[token.range.0..token.range.1]),
        "t_i32" => Node::TypeI32,
        "t_i64" => Node::TypeI64,
        "t_f32" => Node::TypeF32,
        "t_f64" => Node::TypeF64,
        "t_string" => Node::TypeString,
        "t_array" => Node::TypeArray(Box::from(parse_type(&token_iter.next().expect(&format!("Expected a type for Array at {},{}", token.range.0, token.range.1)), source, token_iter))),
        "at_decl" => Node::AtDecl(&source[token.range.0+1..token.range.1]),
        "at_decl_with_params" => parse_at_decl_with_params(token, source),
        _ => unimplemented!("Token {} is not implemented", token.name)
    }
}

/// Return the token when the token matches the expected outcome, return an error message otherwise
fn expect_token<'a>(token: &'a Token, expected: Vec<&str>) -> Result<&'a Token, String> {
    let mut err = true;
    for expected in &expected {
        if &token.name == expected {
            err = false;
        }
    }
    if err {
        Err(format!("Expected {:?}", expected))
    } else {
        Ok(&token)
    }
}

/// A node in the source code
#[derive(Debug, PartialEq)]
pub enum Node<'a> {
    DocComment(&'a str),
    Comment(&'a str),
    /// Import statement containing either and `Ident` or a `String`
    Import(Box<Node<'a>>),
    /// let x = 5 (name: x, type: i32, value: 5)
    Let { name: Box<Node<'a>>, ty: Box<Node<'a>>, value: Box<Node<'a>> },
    // Types
    TypeI32,
    TypeI64,
    TypeF32,
    TypeF64,
    TypeString,
    /// Array<Subtype>
    TypeArray(Box<Node<'a>>),
    /// String literal
    StringLiteral(&'a str),
    Int32Val(i32),
    Int64Val(i64),
    /// Identifier
    Ident(&'a str),
    /// `@decl`
    /// AtDecl(name)
    AtDecl(&'a str),
    /// `@decl("file.wat")`, `@decl("string", test: "value")`
    /// AtDeclWithParams(name, params)
    AtDeclWithParams(&'a str, Vec<Box<Node<'a>>>),
    ParamCall { name: &'a str, value: Box<Node<'a>> },
    
    /// No token can be `__None`, this would be a bug in the parser
    __None
}

impl Node<'_> {
    /// get the name of the ident, or None if the type is not an ident
    pub fn get_ident_name(&self) -> Option<&str> {
        match self {
            Self::Ident(val) => Some(val),
            _ => None
        }
    }
    /// Type to string (e.g. `TypeI32` -> `i32`)
    pub fn get_type_str(&self) -> Option<String> {
        match self {
            Self::TypeI32 => Some("i32".to_string()),
            Self::TypeI64 => Some("i64".to_string()),
            Self::TypeF32 => Some("f32".to_string()),
            Self::TypeF64 => Some("f64".to_string()),
            Self::TypeString => Some("String".to_string()),
            Self::TypeArray(inner) => {
                let str = format!("Array<{}>", *inner.get_type_str().as_ref().expect("Expected type declaration for array"));
                Some(str)
            },
            _ => None
        }
    }
    
    /// Get the value of a literal
    pub fn get_literal_value(&self) -> Option<String> {
        match self {
            Self::Int32Val(val) => Some(val.to_string()),
            _ => None
        }
    }
}
