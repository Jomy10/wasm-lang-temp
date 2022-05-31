//! Extensive math tests
//! making sure that math is executed properly

use compiler::codegen::wat::generate_wat;
use compiler::tree_sitter::{Parser, language};
use wasmer::{imports, wat2wasm, Store, Module, Instance};

// ==========================
// i32
// ==========================

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

// ==========================
// f32
// ==========================

#[test]
fn test_addition_f32() {
    test_math_f32("6.8 + 7.2", 6.8 + 7.2);
}

#[test]
fn test_subtraction_f32() {
    test_math_f32("5.0 - 4.3", 5.0 - 4.3);
}

#[test]
fn test_multiplication_f32() {
    test_math_f32("5.0 * 5.5", 5.0 * 5.5);
}

#[test]
fn test_dividing_f32() {
    test_math_f32("7.8 / 9.2", 7.8 / 9.2);
}

#[test]
fn test_div_with_remain_f32() {
    test_math_f32("99.0 / 69.420", 99.0 / 69.420);
}

#[test]
fn test_unary_min_f32() {
    test_math_f32("-2.4", -2.4);
}

#[test]
fn test_add_with_unary_min_f32() {
    test_math_f32("-3.8 + 2.9", -3.8 + 2.9);
}

#[test]
fn test_add_with_unary_min_outcome_pos_f32() {
    test_math_f32("-3.7 + 4.0", -3.7 + 4.0);
}

#[test]
fn test_math1_f32() {
    test_math_f32("(5.8 * 6.9) + 9.0 * 4.98 / (87.7 - 1.5) / 8.3 /9.67 * 2.02 -2.02567", (5.8 * 6.9) + 9.0 * 4.98 / (87.7 - 1.5) / 8.3 /9.67 * 2.02 -2.02567);
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

fn test_math_f32(expr: &str, outcome: f32) {
    let source = format!("pub func math() -> f32 {{ return {expr} }}");

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
    
    let math_func = instance.exports.get_native_function::<(), f32>("math").unwrap();
    
    let res: f32 = math_func.call().unwrap();
     
    assert_eq!(res, outcome);
}
