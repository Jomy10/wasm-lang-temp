use compiler::codegen::gen_wat::generate_wat;
use tree_sitter::Parser;
use tree_sitter_wasm_lang::language;
use regex::Regex;
use concat_string::concat_string;

#[test]
fn test_func() {
    let source = r#"func someFunc() {}"#;
    let expected = r#"\(func \$\d+\$someFunc\s*\)"#;

    test_compiler(source, expected);
}

#[test]
fn test_pub_func() {
    let source = r#"pub func someFunc() {}"#;
    let expected = r#"\(export "someFunc" \(func \$\d+\$someFunc\)\)\(func \$\d+\$someFunc\s+\)"#;
    
    test_compiler(source, expected);
}

#[test]
fn test_main_func() {
    let source = r#"pub func main() {}"#;
    let expected = r#"\(export "main" \(func \$main\)\)\(export "_start" \(func \$main\)\)\(func \$main\s+\)"#;
    
    test_compiler(source, expected);
}

#[test]
fn test_func_with_param() {
    let source = r#"func someFunc(param: i32) {}"#;
    let expected = r#"\(func \$\d+\$someFunc \(param \$\d+\$param i32\)\s+\)"#;
    
    test_compiler(source, expected);
}

#[test]
fn test_func_with_params() {
    let source = r#"func someFunc(param: i32, other: i32) {}"#;
    let expected = r#"\(func \$\d+\$someFunc \(param \$\d+\$param i32\)\(param \$\d+\$other i32\)\s+\)"#;
    
    test_compiler(source, expected);
}

#[test]
fn test_var_decl_infer_type() {
    let source = r#"func someFunc() { var x = 24 }"#;
    let expected = r#"\(func \$\d+\$someFunc \(local \$\d+\$x i32\) i32.const 24 local.set \$\d+\$x\s+\)"#;
    
    test_compiler(source, expected);
}

#[test]
fn test_var_decl_with_type() {
    let source = r#"func someFunc() { var x: i32 = 25 }"#;
    let expected = r#"\(func \$\d+\$someFunc \(local \$\d+\$x i32\) i32.const 25 local.set \$\d+\$x\s+\)"#;

    test_compiler(source, expected);
}

#[test]
fn test_return_variable() {
    let source = r#"pub func someFunc() -> i32 { var x = 25 return x }"#;
    let expected = r#"(export "someFunc" (func !fn!))(func !fn! (result i32)\s*(local !varx! i32) i32.const 25 local.set !varx! local.get !varx! return\s*)"#;
    let expected = expected.replace("(", r"\(").replace(")", r"\)").replace("!fn!", r"\$\d+\$someFunc").replace("!varx!", r"\$\d+\$x");
    
    test_compiler(source, &expected);
}

#[test]
fn test_return_int() {
    let source = r#"func someFunc() -> i32 { return 1 }"#;
    let expected = r#"\(func \$\d+\$someFunc\s+\(result i32\)\s+i32.const 1 return\s*\)"#;
    
    test_compiler(source, expected);
}

#[test]
fn test_empty_return() {
    let source = "func someFunc() { return }";
    let expected = r#"\(func \$\d+\$someFunc\s+return\s*\)"#;
    
    test_compiler(source, expected);
}

#[test]
#[should_panic(expected = "No return type declared for this function, but a value is returned")]
fn test_no_return_but_value_returned() {
    let source = "func someFunc() { return 5 }";
    test_compiles(&source);
}

// TODO
#[test]
#[should_panic]
fn test_return_but_no_value_returned() {
    let source = r#"func someFunc() -> i32 { }"#;
    let expected = r#"\(func \$\d+\$someFunc \(result i32\)\s*\)"#;
    
    test_compiler(source, expected);
}

#[test]
fn test_mul() {
    let source = r#"func someFunc() -> i32 { return 5 * 6 }"#;
    let expected = r#"\(func \$\d+\$someFunc \(result i32\)\s*i32.const 5 i32.const 6 i32.mul return\s*\)"#;
    
    test_compiler(source, expected);
}

#[test]
fn test_div() {
    let source = r#"func someFunc() -> i32 { return 5 / 6 }"#;
    let expected = r#"\(func \$\d+\$someFunc \(result i32\)\s*i32.const 5 i32.const 6 i32.div_s return\s*\)"#;
    
    test_compiler(source, expected);
}

#[test]
fn test_add() {
    let source = r#"func someFunc() -> i32 { return 5 + 6 }"#;
    let expected = r#"\(func \$\d+\$someFunc \(result i32\)\s*i32.const 5 i32.const 6 i32.add return\s*\)"#;
    
    test_compiler(source, expected);
}

#[test]
fn test_sub() {
    let source = r#"func someFunc() -> i32 { return 5 - 6 }"#;
    let expected = r#"\(func \$\d+\$someFunc \(result i32\)\s*i32.const 5 i32.const 6 i32.sub return\s*\)"#;
    
    test_compiler(source, expected);
}

#[test]
fn test_math_add_and_mul() {
    let source = r#"func someFunc() -> i32 { return 5 - 6 * 7 }"#;
    let expected = r#"\(func \$\d+\$someFunc \(result i32\)\s*i32.const 5 i32.const 6 i32.const 7 i32.mul i32.sub return\s*\)"#;
    
    test_compiler(source, expected);
}

#[test]
fn tets_math_with_brackets() {
    let source = r#"func someFunc() -> i32 { return (5 - 6) * 7 }"#;
    let expected = r#"\(func \$\d+\$someFunc \(result i32\)\s*i32.const 5 i32.const 6 i32.sub i32.const 7 i32.mul return\s*\)"#;

    test_compiler(source, expected);
}

#[test]
fn test_unary_op_neg() {
    let source = r#"func someFunc() -> i32 { return -8 }"#;
    let expected = r#"\(func \$\d+\$someFunc \(result i32\)\s*i32.const -1 i32.const 8 i32.mul return\s*\)"#;

    test_compiler(source, expected);
    
}

// ============================================================================
// Helper functions
// ============================================================================

/// Also adds "(module)" to expected
fn test_compiler(source: &str, expected: &str) {
    let mut parser = Parser::new();
    parser
        .set_language(language())
        .expect("Error loading language");
    let tree = parser.parse(source, None).unwrap();
    let output = generate_wat(&tree, &source, true);
    
    let re = Regex::new(&concat_string!(r"\(module ", expected, r"\)")).unwrap();
    println!("Output: {}", output);
    println!("Expected: {}", re);
    assert!(re.is_match(&output));
}

// TODO: also compile to wasm and test
/// Simply compiles the source code. Used when testing wheter a function compiles or fails to compile.
fn test_compiles(source: &str) {
    let mut parser = Parser::new();
    parser
        .set_language(language())
        .expect("Error loading language");
    let tree = parser.parse(source, None).unwrap();
    let output = generate_wat(&tree, &source, true);
    
    println!("output: {}", output);
}
