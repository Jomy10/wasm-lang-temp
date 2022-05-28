use std::rc::Rc;

use parser::lexer::*;
use parser::parser::*;
use std::collections::HashMap;

#[test]
/// Test wheter the nodes are being adjusted correctly
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
            params: Vec::new(),
            return_type: Type::Void,
        }            
    ]);
    
    assert_eq!(parsed, expected)
}

#[test]
/// Test wheter the correct scopes are being generated
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
