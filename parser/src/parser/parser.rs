use std::collections::HashMap;
use std::iter::Peekable;
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
    println!("Parsing token {:?}", token);
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
        _ => unimplemented!("Token {} is not implemented", token.name)
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
    
    let _ = expect_token(tokens.next().unwrap(), "open_curly__bracket");
    // TODO: function body
    let _ = expect_token(tokens.next().unwrap(), "closed_curly_bracket");

    return Node::Func { 
        ext_name: &source[ident_token.range.0..ident_token.range.1], 
        int_name: concat_string!(filename, "$", token.range.0.to_string(), "$", &source[ident_token.range.0..ident_token.range.1]), 
        public,
        body: Vec::new(),
        params,
    };
}

#[allow(unused)]
/// Return the token when the token matches one of the expected outcomes, return an error message otherwise
fn expect_token_of<'a>(token: &'a Token, expected: Vec<&str>) -> Result<&'a Token<'a>, String> {
    let mut err = true;
    for expected in &expected {
        if token.name == *expected {
            err = false;
        }
    }
    
    if err {
        Err(format!("Expected {:?}, got {:?}", expected, token))
    } else {
        Ok(token)
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