use std::fs::read;

#[test]
fn gen_wasm() {
    let expected = read("tests/gen_wasm_test_expected.wasm").unwrap();
    let generated_wasm = codegen::gen_wasm::wat2wasm(r#"(module
	(export "test" (func $test))
	(func $test

	    (result i32)
	    (local $myVar i32)
		i32.const 5
		local.set $myVar
		local.get $myVar
	)
)
"#).unwrap();
    
    assert_eq!(expected, generated_wasm)
}