use std::collections::HashMap;
use std::iter::Peekable;
use std::rc::Rc;
use std::slice::Iter;

use crate::lexer::Token;
use crate::parser::*;
use concat_string::concat_string;

pub fn parse<'a>(tokens: &'a Vec<Token>, source: &'a str, filename: &str) -> Vec<Node<'a>> {
    let mut tokens = tokens.iter().peekable();
    
    let mut nodes: Vec<Node> = Vec::new();
    while let Some(token) = tokens.next() {
        nodes.push(parse_token(&token, &source, &mut tokens, filename, None))
    }

    return nodes
}

/// Parse a token and return a `Node`
fn parse_token<'a>(token: &Token, source: &'a str, tokens: &mut Peekable<Iter<'a, Token>>, filename: &str, meta: Option<HashMap<String, String>>) -> Node<'a> {
    match token.name {
        "pub" => {
            // Tokens that can follow `pub`
            let next_token = expect_token(tokens.next().unwrap(), "func").unwrap();
            parse_token(next_token, source, tokens, filename, 
                Some(HashMap::from([("prev_is_pub_keyword".to_string(), "true".to_string())]))
            )
        },
        "func" => {
            let is_pub = if let Some(meta) = meta {
                meta
                    .get("prev_is_pub_keyword")
                    .map(|v| v.to_string())
                    .unwrap_or("false".to_string())
            } else {
                "false".to_string() 
            };
            let is_pub = if &is_pub == "true" { true } else { false };
            parse_func(is_pub, token, source, tokens, filename)
        },
        "var" => {
            parse_var(token, source, tokens, filename)
        },
        "return" => {
            parse_return(source, tokens, filename, &meta)
        },
        "int_literal" => {
            parse_int_literal(token, source)
        },
        "ident" => {
            parse_ident(token, source, &meta)
        }
        _ => panic!("Token {} was not expected. This is a bug in the parser, please open an issue. Happened in parser.rs at line {}", token.name, line!())
    }
}

/// Parse a function declaration
/// `{pub} func ident(/* params */) { /* body */ }`
fn parse_func<'a>(public: bool, token: &Token, source: &'a str, tokens: &mut Peekable<Iter<'a, Token>>, filename: &str) -> Node<'a> {
    let ident_token = expect_token(tokens.next().unwrap(), "ident").unwrap();
    let _ = expect_token(tokens.next().unwrap(), "open_bracket");
    // function params
    let params: Vec<FuncParam> = if peek_token(tokens, "ident") {
        let mut v: Vec<FuncParam> = Vec::new();

        loop {
            let name = unsafe { tokens.next().unwrap_unchecked() };
            let _temp = expect_token(tokens.next().unwrap(), "colon");
            let t = expect_token(tokens.next().unwrap(), "type").unwrap();
            let t: Type = Type::from(&source[t.range.0..t.range.1]);

            v.push(FuncParam { refer_name: &source[name.range.0..name.range.1], int_name: format!("{filename}${}${}", name.range.0, &source[name.range.0..name.range.1]), t });
            if peek_token(tokens, "comma") {
                let _temp = tokens.next(); // ,
                if !(peek_token(tokens, "ident")) {
                    break;
                }
            } else {
                break;
            }
        }

        v
    } else {
        Vec::new()
    };

    let _ = expect_token(tokens.next().unwrap(), "closed_bracket");
    
    let return_type: Type = if peek_token(tokens, "arrow") {
        let _ = tokens.next(); // ->
        let r#type = expect_token(tokens.next().unwrap(), "type").expect("Expected a type after ->");
        parse_type(r#type, source)
    } else {
        Type::Void
    };
    
    let _ = expect_token(tokens.next().unwrap(), "open_curly__bracket");
    
    let func_name = &source[ident_token.range.0..ident_token.range.1];
    
    let mut body: Vec<Node> = Vec::new();
    if peek_token(tokens, "closed_curly_bracket") {
        let _ = tokens.next();
    } else {
        // Function has a body
        let mut nested_cur_brac = 0;
        while let Some(token) = tokens.next()  {
            if token.name == "closed_curly_bracket" {
                if nested_cur_brac == 0 { 
                    break; 
                } else {
                    nested_cur_brac -= 1;
                }
            }
            if token.name == "open_curly_bracket" {
                nested_cur_brac += 1;
            }
            body.push(parse_token(token, source, tokens, filename, Some(HashMap::from([("function".to_string(), func_name.to_string())]))));
        }
    }

    return Node::Func { 
        ext_name: func_name, 
        int_name: concat_string!(filename, "$", token.range.0.to_string(), "$", func_name), 
        public,
        params,
        return_type,
        body,
    };
}

/// Parse a variable declaration
/// `var m: i32 = 5` `var m = 5`
fn parse_var<'a>(token: &Token, source: &'a str, tokens: &mut Peekable<Iter<'a, Token>>, filename: &str) -> Node<'a> {
    let name = expect_token(tokens.next().unwrap(), "ident").unwrap();
    if peek_token(tokens, "colon") {
        let _ = tokens.next();
        let t = expect_token(tokens.next().unwrap(), "type").unwrap();
        let _ = expect_token(tokens.next().unwrap(), "equal_sign").unwrap();
        let (value, _) = expect_token_of(tokens.next().unwrap(), vec!["int_literal"]).unwrap(); // TODO: allow other things than int

        let t = match &source[t.range.0..t.range.1] {
            "i32" => Type::i32,
            _ => unimplemented!()
        };
        
        return Node::VarDecl { 
            ext_name: &source[name.range.0..name.range.1], 
            int_name: format!("{}${}${}", filename, token.range.0, &source[name.range.0..name.range.1]), 
            t, 
            initial_value: Some(Rc::new(Node::Literal(LiteralValue::new(&source[value.range.0..value.range.1], t))))
        }
    } else {
        // TODO: handle if no = present; `var m` <- no initial value (todo: what happens in wasm?)
        let _ = expect_token(tokens.next().unwrap(), "equal_sign").unwrap();
        let (value, t) = expect_token_of(tokens.next().unwrap(), vec!["int_literal"]).unwrap(); // TODO: allow other things than int

        // infer type
        let inferred_type: Type = if &t == "int_literal" {
            Type::i32
        } else {
            panic!("Couldn't infer type (TODO: line number, etc.)");
        };

        return Node::VarDecl { 
            ext_name: &source[name.range.0..name.range.1], 
            int_name: format!("{}${}${}", filename, token.range.0, &source[name.range.0..name.range.1]), 
            t: inferred_type, 
            initial_value: Some(Rc::new(Node::Literal(LiteralValue::new(&source[value.range.0..value.range.1], inferred_type))))
        }
    }
}


fn parse_return<'a>(source: &'a str, tokens: &mut Peekable<Iter<'a, Token>>, filename: &str, meta: &Option<HashMap<String, String>>) -> Node<'a> {
    if peek_token(tokens, "closed_curly_bracket") {
        Node::Return(None)
    } else {
        Node::Return (
            Some(Rc::new(
                parse_token(tokens.next().unwrap(), source, tokens, filename, meta.clone())
            ))
        )
    }
}

fn parse_int_literal<'a>(token: &Token, source: &'a str) -> Node<'a> {
    Node::Literal(
        LiteralValue::i32(&source[token.range.0..token.range.1])
    )
}

fn parse_ident<'a>(token: &Token, source: &'a str, meta: &Option<HashMap<String, String>>) -> Node<'a> {
    // TODO: check wether is variable
    if let Some(meta) = meta {
        Node::Variable {
            name: &source[token.range.0..token.range.1],
            function: meta.get("function").unwrap().clone(),
            int_name: None,
        }
    } else {
        panic!("Variable can only be used inside of a function")
    }
}

/// Parse token "type" (e.g. i32, i64, etc.)
fn parse_type(token: &Token, source: &str) -> Type {
    return Type::from(&source[token.range.0..token.range.1]);
}

#[allow(unused)]
/// Return the token when the token matches one of the expected outcomes and what matched, return an error message otherwise
fn expect_token_of<'a>(token: &'a Token, expected: Vec<&str>) -> Result<(&'a Token<'a>, String), String> {
    let mut err = true;
    let mut matched = "";
    for expected in &expected {
        if token.name == *expected {
            err = false;
            matched = *expected;
        }
    }
    
    if err {
        Err(format!("Expected {:?}, got {:?}", expected, token))
    } else {
        Ok((token, matched.to_string()))
    }
}

/// Return the token when the token matches the expected outcome, return an error message otherwise
fn expect_token<'a>(token: &'a Token, expected: &str) -> Result<&'a Token<'a>, String> {
    if token.name != expected {
        Err(format!("Expected {}, got {:?}", expected, token))
    } else {
        Ok(token)
    }
}

/// Peak to the next token. Return true if it is the expected token, false otherwise
fn peek_token<'a>(tokens: &'a mut Peekable<Iter<Token>>, expected: &str) -> bool {
    if let Some(token) = tokens.peek() {
        return token.name == expected;
    } else {
        false
    }
}
