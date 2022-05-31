//! Extensive math tests
//! making sure that math is executed properly

use compiler::codegen::wat::generate_wat;
use compiler::tree_sitter::{Parser, language};
use wasmer::{imports, wat2wasm, Store, Module, Instance};

#[test]
fn test_addition() {
    test_math("5 + 5", 5 + 5);
}

#[test]
fn test_subtraction() {
    test_math("5 - 4", 1);
}

#[test]
fn test_multiplication() {
    test_math("5 * 5", 25);
}

#[test]
fn test_dividing() {
    test_math("5 / 5", 1);
}

#[test]
fn test_div_with_remain() {
    test_math("5 / 4", 1);
}

#[test]
fn test_unary_min() {
    test_math("-2", -2);
}

#[test]
fn test_add_with_unary_min() {
    test_math("-3 + 2", -1);
}

#[test]
fn test_add_with_unary_min_outcome_pos() {
    test_math("-3 + 4", 1);
}

#[test]
fn test_math1() {
    test_math("(5 * 6) + 9 * 4 / (87 - 1) / 8 /9 * 2 -2", (5 * 6) + 9 * 4 / (87 - 1) / 8 /9 * 2 -2);
}

fn test_math(expr: &str, outcome: i32) {
    let source = format!("pub func math() -> i32 {{ return {expr} }}");
    let mut parser = Parser::new();
    parser
        .set_language(language())
        .expect("Error loading language");
    
    let tree = parser.parse(&source, None).unwrap();
    let output = generate_wat(&tree, &source, false);
    let output = output.into_bytes();
    
    let wasm_bytes = wat2wasm(&output).unwrap();
    
    let store = Store::default();
    
    let module = Module::new(&store, wasm_bytes).unwrap();
    
    let import_object = imports! {};    
    
    let instance = Instance::new(&module, &import_object).unwrap();
    
    let math_func = instance.exports.get_native_function::<(), i32>("math").unwrap();
    
    let res: i32 = math_func.call().unwrap();
    
    assert_eq!(res, outcome);
}
