use std::rc::Rc;

use parser::lexer::*;
use parser::parser::*;

#[test]
fn test_func() {
    let source = r#"func someFunc() {}"#;
    let expected = Vec::from([
        Node::Func { 
            ext_name: "someFunc", 
            int_name: "main$0$someFunc".to_string(), 
            body: Vec::new(),
            public: false,
            return_type: Type::Void,
            params: Vec::new(), 
        }
    ]);

    test_parser(source, &expected);
}

#[test]
fn test_pub_func() {
    let source = r#"pub func someFunc() {}"#;
    let expected = Vec::from([
        Node::Func { 
            ext_name: "someFunc", 
            int_name: "main$4$someFunc".to_string(), 
            body: Vec::new(),
            public: true,
            return_type: Type::Void,
            params: Vec::new()
        }
    ]);
    
    test_parser(source, &expected);
}

#[test]
fn test_func_with_param() {
    let source = r#"pub func someFunc(field: i32) {}"#;
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
            return_type: Type::Void,
        }
    ]);
    
    test_parser(source, &expected);
}

#[test]
fn test_func_with_params() {
    let source = r#"pub func someFunc(field: i32, other: i32) {}"#;
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
            return_type: Type::Void,
        }
    ]);
    
    test_parser(source, &expected);
}

#[test]
fn test_var_decl() {
    let source = r#"var m = 5"#;
    let expected = Vec::from([
        Node::VarDecl { 
            ext_name: "m", 
            int_name: "main$0$m".to_string(), 
            t: Type::i32, 
            initial_value: Some(Rc::new(Node::Literal(LiteralValue::i32("5"))))
        }
    ]);

    test_parser(source, &expected);
}

#[test]
fn test_var_decl_with_type() {
    let source = r#"var m: i32 = 5"#;
    let expected = Vec::from([
        Node::VarDecl { 
            ext_name: "m", 
            int_name: "main$0$m".to_string(), 
            t: Type::i32, 
            initial_value: Some(Rc::new(Node::Literal(LiteralValue::i32("5"))))
        }
    ]);

    test_parser(source, &expected);
}

#[test]
fn test_func_with_var_decl_body() {
    let source = r#"func someFunc() { var m: i32 = 5 }"#;
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
            params: Vec::new(),
            return_type: Type::Void,
        }            
    ]);

    test_parser(source, &expected);    
}

#[test]
fn test_func_with_return() {
    let source = r#"func five() { return 5 }"#;
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
            return_type: Type::Void,
        },
    ];
    
    test_parser(source, &expected);
}

#[test]
fn test_func_with_var_return() {
    let source = r#"func someFunc() { var m: i32 = 5 return m }"#;
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
            params: Vec::new(),
            return_type: Type::Void,
        }            
    ]);

    // Post parsing version tested in `post_parser_tests.rs`
    test_parser_no_post(source, &expected);    
}

#[test]
fn test_func_with_return_type() {
    let source = r#"func someFunc() -> i32 { }"#;
    let expected = Vec::from([
        Node::Func {
            ext_name: "someFunc",
            int_name: String::from("main$0$someFunc"),
            public: false,
            params: Vec::new(),
            return_type: Type::i32,
            body: Vec::new(),
        }
    ]);

    test_parser(source, &expected);    
}

// ================================================================
// Helper functions
// ================================================================

fn test_parser(source: &str, expected: &Vec<Node>) {
    let tokens = tokenize(source);
    let mut parsed = parse(&tokens, source, "main");
    let post_parser = PostParser::new();
    post_parser.post_parse(&mut parsed);
    
    assert_eq!(expected, &parsed)
}

/// Don't apply post-parsing
fn test_parser_no_post(source: &str, expected: &Vec<Node>) {
    let tokens = tokenize(source);
    let parsed = parse(&tokens, source, "main");
    
    assert_eq!(expected, &parsed)
}
