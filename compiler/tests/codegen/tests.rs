use compiler::codegen::gen_wat::generate_wat;
use parser::{lexer::tokenize, parser::parse};

#[test]
fn test_func() {
    let source = r#"func someFunc() {}"#;
    let tokens = tokenize(source);
    let parsed = parse(&tokens, source, "main");
    let output = generate_wat(&parsed);
    let expected = "(func $main$0$someFunc  )";

    assert_eq!(output, expected);
}

#[test]
fn test_pub_func() {
    let source = r#"pub func someFunc() {}"#;
    let tokens = tokenize(source);
    let parsed = parse(&tokens, source, "main");
    let output = generate_wat(&parsed);
    let expected = r#"(export "someFunc" (func $main$4$someFunc))(func $main$4$someFunc  )"#;

    assert_eq!(output, expected);
}

#[test]
fn test_main_func() {
    let source = r#"pub func main() {}"#;
    let tokens = tokenize(source);
    let parsed = parse(&tokens, source, "main");
    let output = generate_wat(&parsed);
    let expected = r#"(export "main" (func $main$4$main))(export "_start" (func $main$4$main))(func $main$4$main  )"#;

    assert_eq!(output, expected);
}

#[test]
fn test_func_with_param() {
    let source = r#"func someFunc(param: i32) {}"#;
    let tokens = tokenize(source);
    let parsed = parse(&tokens, source, "main");
    let output = generate_wat(&parsed);
    let expected = "(func $main$0$someFunc (param $main$14$param i32) )";

    assert_eq!(output, expected);
}

#[test]
fn test_func_with_params() {
    let source = r#"func someFunc(param: i32, other: i32) {}"#;
    let tokens = tokenize(source);
    let parsed = parse(&tokens, source, "main");
    let output = generate_wat(&parsed);
    let expected = "(func $main$0$someFunc (param $main$14$param i32)(param $main$26$other i32) )";

    assert_eq!(output, expected);
}

#[test]
fn test_var_decl() {
    let source = r#"func someFunc() { var x = 24 }"#;
    let tokens = tokenize(source);
    let parsed = parse(&tokens, source, "main");
    let output = generate_wat(&parsed);
    let expected = "(func $main$0$someFunc (local $main$18$x i32) i32.const 24 local.set $main$18$x)";

    assert_eq!(output, expected);
}

#[test]
fn test_var_decl_with_type() {
    let source = r#"func someFunc() { var x: i32 = 25 }"#;
    let tokens = tokenize(source);
    let parsed = parse(&tokens, source, "main");
    let output = generate_wat(&parsed);
    let expected = "(func $main$0$someFunc (local $main$18$x i32) i32.const 25 local.set $main$18$x)";

    assert_eq!(output, expected);
}

#[test]
fn test_return_variable() {
    let source = r#"pub func someFunc() { var x = 25 return x }"#;
    let tokens = tokenize(source);
    let parsed = parse(&tokens, source, "main");
    let output = generate_wat(&parsed);
    let expected = "(func $main$4$someFunc (local $main$18$x i32) i32.const 25 local.set $main$18$x local.get $main$18$x)";
    
    assert_eq!(output, expected);
}