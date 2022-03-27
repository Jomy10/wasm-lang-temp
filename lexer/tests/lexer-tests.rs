use lexer::*;

#[test]
fn lexer_test() {
    // TODO: all tokens
    let input = r#"import std
// Comment
var test = 5
/// Doc comment
pub let _var=4

@deprecated
@available(package: 1.0)
func test() -> i32 {
    some_body()
}
    "#;
    
    let tokens = tokenize(&input);
    
    let expected_tokens: Vec<Token> = vec![
        Token::new("import", (0,6)), Token::new("ident", (7,10)),
        Token::new("comment", (11, 21)),
        Token::new("var", (22, 25)), Token::new("ident", (26, 30)), Token::new("equal", (31, 32)), Token::new("int", (33,34)),
        Token::new("doc_comment", (35, 50)),
        Token::new("public", (51, 54)), Token::new("let", (55, 58)), Token::new("ident", (59, 63)), Token::new("equal", (63, 64)), Token::new("int", (64,65)),
        Token::new("at_decl", (67, 78)),
        Token::new("at_decl_with_params", (79, 103)),
        Token::new("func", (104, 108)), Token::new("func_decl", (109, 115)), Token::new("return_a", (116, 118)), Token::new("t_i32", (119, 122)), Token::new("body", (123, 142))
    ];
    
    assert_eq!(expected_tokens, tokens)
}
