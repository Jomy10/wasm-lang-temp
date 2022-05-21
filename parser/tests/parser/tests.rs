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

    // TODO: impl equality
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

    // TODO: impl equality
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
                Node::Return {
                    value: Some(Rc::new(Node::Literal(LiteralValue::i32("5")))),
                }
            ],
            public: false,
            params: Vec::new(),
        },
    ];
}