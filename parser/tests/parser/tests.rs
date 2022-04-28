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