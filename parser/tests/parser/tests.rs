use std::rc::Rc;

use parser::lexer::*;
use parser::parser::*;

#[test]
fn test_func() {
    let source = r#"func someFunc() {}"#;
    let tokens = tokenize(source);
    let parsed = parse(&tokens, source, "main");
    let expected = Vec::from([
        Node::Func { 
            ext_name: "someFunc", 
            int_name: "main$0$someFunc".to_string(), 
            body: Vec::new(),
            public: false,
            params: Vec::new(), 
        }
    ]);

    assert_eq!(parsed, expected);
}

#[test]
fn test_pub_func() {
    let source = r#"pub func someFunc() {}"#;
    let tokens = tokenize(source);
    let parsed = parse(&tokens, source, "main");
    let expected = Vec::from([
        Node::Func { 
            ext_name: "someFunc", 
            int_name: "main$4$someFunc".to_string(), 
            body: Vec::new(),
            public: true, 
            params: Vec::new()
        }
    ]);

    assert_eq!(parsed, expected);
}

#[test]
fn test_func_with_param() {
    let source = r#"pub func someFunc(field: i32) {}"#;
    let tokens = tokenize(source);
    let parsed = parse(&tokens, source, "main");
    let expected = Vec::from([
        Node::Func { 
            ext_name: "someFunc", 
            int_name: "main$4$someFunc".to_string(), 
            body: Vec::new(),
            public: true, 
            params: vec![
                FuncParam { 
                    refer_name: "field", 
                    int_name: "main$18$field".to_string(), 
                    t: Type::i32
                }
            ],
        }
    ]);

    assert_eq!(parsed, expected);
}

#[test]
fn test_func_with_params() {
    let source = r#"pub func someFunc(field: i32, other: i32) {}"#;
    let tokens = tokenize(source);
    let parsed = parse(&tokens, source, "main");
    let expected = Vec::from([
        Node::Func { 
            ext_name: "someFunc", 
            int_name: "main$4$someFunc".to_string(), 
            body: Vec::new(),
            public: true, 
            params: vec![
                FuncParam { 
                    refer_name: "field", 
                    int_name: "main$18$field".to_string(), 
                    t: Type::i32
                },
                FuncParam { 
                    refer_name: "other", 
                    int_name: "main$30$other".to_string(), 
                    t: Type::i32
                }
            ],
        }
    ]);

    assert_eq!(parsed, expected);
}

#[test]
fn test_var_decl() {
    let source = r#"var m = 5"#;
    let tokens = tokenize(source);
    let parsed = parse(&tokens, source, "main");
    let expected = Vec::from([
        Node::VarDecl { 
            ext_name: "m", 
            int_name: "main$0$m".to_string(), 
            t: Type::i32, 
            initial_value: Some(Rc::new(Node::Literal(LiteralValue::i32("5"))))
        }
    ]);

    assert_eq!(parsed, expected);
}

#[test]
fn test_var_decl_with_type() {
    let source = r#"var m: i32 = 5"#;
    let tokens = tokenize(source);
    let parsed = parse(&tokens, source, "main");
    let expected = Vec::from([
        Node::VarDecl { 
            ext_name: "m", 
            int_name: "main$0$m".to_string(), 
            t: Type::i32, 
            initial_value: Some(Rc::new(Node::Literal(LiteralValue::i32("5"))))
        }
    ]);

    assert_eq!(parsed, expected);
}

#[test]
fn test_func_with_var_decl_body() {
    let source = r#"func someFunc() { var m: i32 = 5 }"#;
    let tokens = tokenize(source);
    let parsed = parse(&tokens, source, "main");
    let expected = Vec::from([
        Node::Func { 
            ext_name: "someFunc", 
            int_name: "main$0$someFunc".to_string(), 
            body: vec![
                Node::VarDecl {
                    ext_name: "m",
                    int_name: "main$18$m".to_string(),
                    t: Type::i32,
                    initial_value: Some(Rc::new(Node::Literal(LiteralValue::i32("5")))),
                },
            ],
            public: false,
            params: Vec::new()
        }            
    ]);
    
    assert_eq!(parsed, expected)
}

#[test]
fn test_func_with_return() {
    let source = r#"func five() { return 5 }"#;
    let tokens = tokenize(source);
    let parsed = parse(&tokens, source, "main");
    let expected = vec![
        Node::Func {
            ext_name: "five",
            int_name: "main$0$five".to_string(),
            body: vec![
                Node::Return (
                    Some(Rc::new(Node::Literal(LiteralValue::i32("5")))),
                )
            ],
            public: false,
            params: Vec::new(),
        },
    ];
    
    assert_eq!(parsed, expected)
}

#[test]
fn test_func_with_var_return() {
    let source = r#"func someFunc() { var m: i32 = 5 return m }"#;
    let tokens = tokenize(source);
    let parsed = parse(&tokens, source, "main");
    let expected = Vec::from([
        Node::Func { 
            ext_name: "someFunc", 
            int_name: "main$0$someFunc".to_string(), 
            body: vec![
                Node::VarDecl {
                    ext_name: "m",
                    int_name: "main$18$m".to_string(),
                    t: Type::i32,
                    initial_value: Some(Rc::new(Node::Literal(LiteralValue::i32("5")))),
                },
                Node::Return(
                    Some(Rc::new(Node::Variable {
                        name: "m",
                        function: "someFunc".to_string(),
                        int_name: None
                    }))
                )
            ],
            public: false,
            params: Vec::new()
        }            
    ]);
    
    assert_eq!(parsed, expected)
}


////////////////////////
// post parsing tests //
////////////////////////
use std::collections::HashMap;

#[test]
fn test_post_parse_nodes() {
    let source = r#"func someFunc() { var m: i32 = 5 return m }"#;
    let tokens = tokenize(source);
    let mut parsed = parse(&tokens, source, "main");
    let post_parser = PostParser::new();
    post_parser.post_parse(&mut parsed);
    
    let expected = Vec::from([
        Node::Func { 
            ext_name: "someFunc", 
            int_name: "main$0$someFunc".to_string(), 
            body: vec![
                Node::VarDecl {
                    ext_name: "m",
                    int_name: "main$18$m".to_string(),
                    t: Type::i32,
                    initial_value: Some(Rc::new(Node::Literal(LiteralValue::i32("5")))),
                },
                Node::Return(
                    Some(Rc::new(Node::Variable {
                        name: "m",
                        function: "someFunc".to_string(),
                        int_name: Some("main$18$m".to_string())
                    }))
                )
            ],
            public: false,
            params: Vec::new()
        }            
    ]);
    
    assert_eq!(parsed, expected)
}

#[test]
fn test_post_parse_scopes() {
    let source = r#"func someFunc() { var m: i32 = 5 return m }"#;
    let tokens = tokenize(source);
    let mut parsed = parse(&tokens, source, "main");
    let post_parser = PostParser::new();
    post_parser.post_parse(&mut parsed);
    
    let scopes = &*post_parser.scopes();
    
    let global_scope = Scope{
        name: String::from("global"),
        vars: HashMap::new(),
        superscope: None
    };
    let func_scope = Scope{
        name: String::from("main$0$someFunc"),
        vars: HashMap::from([(String::from("m"), String::from("main$18$m"))]),
        superscope: Some(global_scope.name.clone())
    };
    let expected = HashMap::from([
        (global_scope.name.clone(), global_scope.clone()),
        (func_scope.name.clone(), func_scope)
    ]);
    
    assert_eq!(scopes, &expected)
} 
