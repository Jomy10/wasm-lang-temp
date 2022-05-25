use compiler::codegen::gen_wat::generate_wat;
use parser::{lexer::*, parser::*};

#[test]
fn test_func() {
    let source = r#"func someFunc() {}"#;
    let expected = "(func $main$0$someFunc  )";

    test_compiler(source, expected);
}

#[test]
fn test_pub_func() {
    let source = r#"pub func someFunc() {}"#;
    let expected = r#"(export "someFunc" (func $main$4$someFunc))(func $main$4$someFunc  )"#;
    
    test_compiler(source, expected);
}

#[test]
fn test_main_func() {
    let source = r#"pub func main() {}"#;
    let expected = r#"(export "main" (func $main$4$main))(export "_start" (func $main$4$main))(func $main$4$main  )"#;
    
    test_compiler(source, expected);
}

#[test]
fn test_func_with_param() {
    let source = r#"func someFunc(param: i32) {}"#;
    let expected = "(func $main$0$someFunc (param $main$14$param i32) )";
    
    test_compiler(source, expected);
}

#[test]
fn test_func_with_params() {
    let source = r#"func someFunc(param: i32, other: i32) {}"#;
    let expected = "(func $main$0$someFunc (param $main$14$param i32)(param $main$26$other i32) )";
    
    test_compiler(source, expected);
}

#[test]
fn test_var_decl() {
    let source = r#"func someFunc() { var x = 24 }"#;
    let expected = "(func $main$0$someFunc (local $main$18$x i32) i32.const 24 local.set $main$18$x )";
    
    test_compiler(source, expected);
}

#[test]
fn test_var_decl_with_type() {
    let source = r#"func someFunc() { var x: i32 = 25 }"#;
    let expected = "(func $main$0$someFunc (local $main$18$x i32) i32.const 25 local.set $main$18$x )";

    test_compiler(source, expected);
}

// TODO: error handling when providing a return without return decl
#[test]
fn test_return_variable() {
    let source = r#"pub func someFunc() { var x = 25 return x }"#;
    let expected = "(export \"someFunc\" (func $main$4$someFunc))(func $main$4$someFunc (local $main$22$x i32) i32.const 25 local.set $main$22$x local.get $main$22$x )";
    
    test_compiler(source, expected);
}

#[test]
fn test_return_decl() {
    let source = r#"func someFunc() -> i32 { }"#;
    let expected = "(func $main$0$someFunc (result i32) )";
    
    test_compiler(source, expected);
}

// ============================================================================
// Helper functions
// ============================================================================

fn test_compiler(source: &str, expected: &str) {
    let tokens = tokenize(source);
    let mut parsed = parse(&tokens, source, "main");
    let post_parser = PostParser::new();
    post_parser.post_parse(&mut parsed);
    let output = generate_wat(&parsed);
    
    assert_eq!(expected, &output);
}
