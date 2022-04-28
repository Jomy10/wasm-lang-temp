use compiler::codegen::gen_wat::generate_wat;
use parser::{lexer::tokenize, parser::parse};

#[test]
fn test_func() {
    let source = r#"func someFunc() {}"#;
    let tokens = tokenize(source);
    let parsed = parse(&tokens, source, "main");
    let output = generate_wat(parsed);
    let expected = "(func $main$0$someFunc )";

    assert_eq!(output, expected);
}

#[test]
fn test_pub_func() {
    let source = r#"pub func someFunc() {}"#;
    let tokens = tokenize(source);
    let parsed = parse(&tokens, source, "main");
    let output = generate_wat(parsed);
    let expected = r#"(export "someFunc" (func $main$4$someFunc))(func $main$4$someFunc )"#;

    assert_eq!(output, expected);
}

#[test]
fn test_main_func() {
    let source = r#"func main() {}"#;
    let tokens = tokenize(source);
    let parsed = parse(&tokens, source, "main");
    let output = generate_wat(parsed);
    let expected = r#"(export "main" (func $main$0$main))(export "_start" (func $main$0$main))(func $main$0$main)"#;

    assert_eq!(output, expected);
}

#[test]
fn test_func_with_param() {
    let source = r#"func someFunc(param: i32) {}"#;
    let tokens = tokenize(source);
    let parsed = parse(&tokens, source, "main");
    let output = generate_wat(parsed);
    let expected = "(func $main$0$someFunc (param $main$14$param i32))";

    assert_eq!(output, expected);
}

#[test]
fn test_func_with_params() {
    let source = r#"func someFunc(param: i32, other: i32) {}"#;
    let tokens = tokenize(source);
    let parsed = parse(&tokens, source, "main");
    let output = generate_wat(parsed);
    let expected = "(func $main$0$someFunc (param $main$14$param i32)(param $main$26$other i32))";

    assert_eq!(output, expected);
}
