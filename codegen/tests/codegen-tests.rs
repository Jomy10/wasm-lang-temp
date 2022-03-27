use codegen::{formatter::format_wat, generate_wat};

#[test]
fn gen_let_const_decl() {
    let source = "\
    let _var = 5
    ";
    let wat = generate_wat(source);
    let formatted = format_wat(&wat, "    ");
    let expectted = r#"(module
    (export "_start" (func $_start))
    (func $_start
        
        
        (local $_var i32)
        i32.const 5
        local.store $_var
))"#;
    println!("{}", formatted);
    assert_eq!(expectted, formatted)
}

#[test]
fn formatter_test() {
    let expected = r#"(module
    (func $fn
        i32.const 0
    )
    (func $fn (local $l i32)
        (return i32)
        i32.const 1
        i32.const 4
        i32.add
    )
)
"#;
    let original = r#"
    (module
(func $fn
        i32.const 0
                )
(func $fn (local $l i32)
                                    (return i32)
        i32.const 1
    i32.const 4
            i32.add
)
    )
    "#;
    
    let formatted = format_wat(original, "    ");
    assert_eq!(expected, formatted);
}