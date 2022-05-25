use parser::lexer::*;

#[test]
fn test_func() {
    let source_code = r#"func someFunc() {}"#;

    let tokens = tokenize(source_code);
    let expected_tokens = Vec::from([
        Token::new("func", (0, 4)),
        Token::new("ident", (5, 13)),
        Token::new("open_bracket", (13,14)),
        Token::new("closed_bracket", (14,15)),
        Token::new("open_curly_bracket", (16, 17)),
        Token::new("closed_curly_bracket", (17,18)),
    ]);

    assert_eq!(tokens, expected_tokens);
}

#[test]
fn test_pub_func() {
    let source_code = r#"pub func someFunc() {}"#;

    let tokens = tokenize(source_code);
    let expected_tokens = Vec::from([
        Token::new("pub", (0,3)),
        Token::new("func", (4, 8)),
        Token::new("ident", (9, 17)),
        Token::new("open_bracket", (17,18)),
        Token::new("closed_bracket", (18,19)),
        Token::new("open_curly_bracket", (20, 21)),
        Token::new("closed_curly_bracket", (21,22)),
    ]);

    assert_eq!(tokens, expected_tokens);
}

#[test]
fn test_func_with_param() {
    let source_code = r#"pub func someFunc(field: i32) {}"#;

    let tokens = tokenize(source_code);
    let expected_tokens = Vec::from([
        Token::new("pub", (0,3)),
        Token::new("func", (4, 8)),
        Token::new("ident", (9, 17)),
        Token::new("open_bracket", (17,18)),
        Token::new("ident", (18,23)),
        Token::new("colon", (23,24)),
        Token::new("type", (25,28)),
        Token::new("closed_bracket", (28,29)),
        Token::new("open_curly_bracket", (30, 31)),
        Token::new("closed_curly_bracket", (31,32)),
    ]);

    assert_eq!(tokens, expected_tokens);
}

#[test]
fn test_func_with_params() {
    let source_code = r#"pub func someFunc(field: i32, otr: i32) {}"#;

    let tokens = tokenize(source_code);
    let expected_tokens = Vec::from([
        Token::new("pub", (0,3)),
        Token::new("func", (4, 8)),
        Token::new("ident", (9, 17)),
        Token::new("open_bracket", (17,18)),
        Token::new("ident", (18,23)),
        Token::new("colon", (23,24)),
        Token::new("type", (25,28)),
        Token::new("comma", (28,29)),
        Token::new("ident", (30,33)),
        Token::new("colon", (33,34)),
        Token::new("type", (35,38)),
        Token::new("closed_bracket", (38,39)),
        Token::new("open_curly_bracket", (40, 41)),
        Token::new("closed_curly_bracket", (41,42)),
    ]);

    assert_eq!(tokens, expected_tokens);
}

#[test]
fn test_var_decl() {
    let source_code = "var m = 6";
    let tokens = tokenize(source_code);
    let expected = vec![
        Token::new("var", (0,3)),
        Token::new("ident", (4,5)),
        Token::new("equal_sign", (6,7)),
        Token::new("int_literal", (8,9)),
    ];

    assert_eq!(tokens, expected);
}

#[test]
fn test_func_with_return_value() {
    let source_code = r#"pub func someFunc(field: i32) { return 5 }"#;

    let tokens = tokenize(source_code);
    let expected_tokens = Vec::from([
        Token::new("pub", (0,3)),
        Token::new("func", (4, 8)),
        Token::new("ident", (9, 17)),
        Token::new("open_bracket", (17,18)),
        Token::new("ident", (18,23)),
        Token::new("colon", (23,24)),
        Token::new("type", (25,28)),
        Token::new("closed_bracket", (28,29)),
        Token::new("open_curly_bracket", (30, 31)),
        Token::new("return", (32, 38)),
        Token::new("int_literal", (39, 40)),
        Token::new("closed_curly_bracket", (41,42)),
    ]);

    assert_eq!(tokens, expected_tokens);
}

#[test]
fn test_return_type() {
    let source_code = r#"-> i32"#;
    let tokens = tokenize(source_code);
    let expected_tokens = Vec::from([
        Token::new("arrow", (0, 2)),
        Token::new("type", (3, 6)),
    ]);
    
    assert_eq!(tokens, expected_tokens);
}

#[test]
fn test_plus_sign() {
    let source = r#"5 + a"#;
    let tokens = tokenize(source);
    let expected_tokens = Vec::from([
        Token::new("int_literal", (0,1)),
        Token::new("plus_sign", (2,3)),
        Token::new("ident", (4,5)),
    ]);
    
    assert_eq!(tokens, expected_tokens);
}

#[test]
fn test_min_sign() {
    let source = r#"-"#;
    let expected = Vec::from([
        Token::new("min_sign", (0,1))
    ]);
    test_tokenizing(source, &expected);
}

#[test]
fn test_slash_sign() {
    let source = r#"/"#;
    let expected = Vec::from([
        Token::new("slash_sign", (0,1))
    ]);
    test_tokenizing(source, &expected);
}

#[test]
fn test_star_sign() {
    let source = r#"*"#;
    let expected = Vec::from([
        Token::new("star_sign", (0,1))
    ]);
    test_tokenizing(source, &expected);
}

#[test]
fn test_other_tokens() {
    let source = "func $$$ \n$\n$";
    let expected_tokens = Vec::from([
        Token::new("func", (0, 4)),
        Token::new("other", (5, 8)),
        Token::new("other", (10, 11)),
        Token::new("other", (12, 13)),
    ]);
    test_tokenizing(source, &expected_tokens);
}

// ==================================================
// Helper functions
// ==================================================

fn test_tokenizing(source: &str, expected: &Vec<Token>) {
    let tokens = tokenize(source);
    assert_eq!(expected, &tokens);
}

