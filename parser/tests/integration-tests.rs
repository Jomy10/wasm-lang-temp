mod parser {
    use parser::{language, Parser};

    #[test]
    fn test_parser_succeeds() {
        let mut parser = Parser::new();
        parser
            .set_language(language())
            .expect("Error loading language");
        parser.parse("", None).unwrap();
    }
}

mod scopes {
    use parser::{language, Parser, Tree, Scope};
    use std::collections::HashMap;

    #[test]
    fn test_global() {
        let source = "var m = 5";
        let expected: HashMap<&str, ScopeContain> = HashMap::from([
            ("global", ScopeContain { vars: Vec::from(["m"]) })
        ]);

        test_scopes(&source, &expected);
    }
    
    #[test]
    fn test_func() {
        let source = "func someFunc() { var m = 5 var s = 3 var m = 6 return m }";
        let expected = HashMap::from([
            ("global", ScopeContain::empty()),
            ("someFunc", ScopeContain { vars: Vec::from(["m", "s"]) })
        ]);
        
        test_scopes(&source, &expected);
    }
    
    // =================================
    // Helper functions
    // =================================
    fn test_scopes(source: &str, expected: &HashMap<&str, ScopeContain>) {
        let tree = parse_source(&source);
        println!("Tree: {}", tree.root_node().to_sexp());
        let scopes = parser::get_scopes(&tree, &source);
        println!("Scopes: {:?}", scopes);
        _test_scopes(&scopes, &expected);
    }
    
    struct ScopeContain<'a> {
        vars: Vec<&'a str>,
    }
    
    impl ScopeContain<'_> {
        fn empty() -> Self {
            Self { vars: Vec::new() }
        }
    }
    
    fn _test_scopes(scopes: &HashMap<usize, Scope>, expected: &HashMap<&str, ScopeContain>) {
        if scopes.len() != expected.len() {
            panic!("Expected and output scope are different size");
        }
        for (_, scope) in scopes {
            let must_contain = expected.get(&scope.scope_name).expect(&format!("Scope was not expected {:?}", &scope));
            if must_contain.vars.len() != scope.vars.len() {
                panic!("Variables not equal in scope {:?}", &scope);
            }
            for var in &must_contain.vars {
                scope.vars.get(*var).unwrap();
            }
            
            break;
        }
    }

    fn parse_source(source: &str) -> Tree {
        let mut parser = Parser::new();
        parser
            .set_language(language())
            .expect("Error loading language");
        parser.parse(source, None).unwrap()
    }
}
