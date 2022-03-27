use lexer::{tokenize};
use parser::{Node, parse};

#[test]
fn parser_test() {
    let source =  r#"
    // Comment
    import module
    /// Doc comment
    import "file"
    let letName: i32 = 5
    let aVar = 3
    let aVar = ""
    let aVar: String = "someString"
    @deprecated
    @_wat("file.wat")
    "#;
    let tokens = tokenize(&source);
    let parsed = parse(&tokens, &source);
    
    let expected_nodes = vec![
        Node::Comment("// Comment"),
        Node::Import(Box::from(Node::Ident("module"))),
        Node::DocComment("/// Doc comment"),
        Node::Import(Box::from(Node::StringLiteral("file"))),
        Node::Let { name: Box::new(Node::Ident("letName")), ty: Box::new(Node::TypeI32), value: Box::new(Node::Int32Val(5)) },
        Node::Let { name: Box::new(Node::Ident("aVar")), ty: Box::new(Node::TypeI32), value: Box::new(Node::Int32Val(3)) },
        Node::Let { name: Box::new(Node::Ident("aVar")), ty: Box::new(Node::TypeString), value: Box::new(Node::StringLiteral("")) },
        Node::Let { name: Box::new(Node::Ident("aVar")), ty: Box::new(Node::TypeString), value: Box::new(Node::StringLiteral("someString")) },
        Node::AtDecl("deprecated"),
        Node::AtDeclWithParams("_wat", vec![Box::from(Node::StringLiteral("file.wat"))])
    ];
    
    assert_eq!(expected_nodes, parsed)
}


#[test]
#[should_panic(expected = "Should be string literal")]
fn type_checker_test() {
    let source =  r#"
    let aname: i32 = "someString"
    "#;
    let tokens = tokenize(&source);
    parse(&tokens, &source);
}
