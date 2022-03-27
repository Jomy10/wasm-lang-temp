use fancy_regex::Regex;

/// Tokenize source code into `Tokens` using regex (see `parser_regex`)
pub fn tokenize(input: &str) -> Vec<Token> {
    let regex = Regex::new(&parser_regex()).unwrap();
    let group_names: Vec<&str> = regex.capture_names().skip(1).map(|x| x.unwrap()).collect::<Vec<&str>>();
    
    let mut matches: Vec<Token> = vec![];
    for captures in regex.captures_iter(input) {
        for name in &group_names {
            if let Some(m) = captures.as_ref().unwrap().name(name) {
                matches.push(Token::new(name, (m.start(), m.end())));
            }
        }
    }
    
    matches
}

#[derive(Debug, PartialEq)]
pub struct Token {
    pub name: String,
    pub range: (usize, usize)
}

impl Token {
    pub fn new(name: &str, range: (usize, usize)) -> Self {
        Self {
            name: name.to_string(), range
        }
    }
    
    pub fn from(tuple: (&str, (usize, usize))) -> Self {
        Self {
            name: tuple.0.to_string(),
            range: tuple.1
        }
    }
}

fn parser_regex() -> String {
    [
        r#"(?P<doc_comment>/// ?[.+ ]*.*)"#, // doc comment
        r#"(?P<comment>// ?[.+ ]*.*)"#, // comment
        r#"(?P<import>import(?= ))"#, // import
        r#"(?P<let>\blet\b)"#, // let
        r#"(?P<var>\bvar\b)"#, // var
        r#"(?<public>\bpub\b)"#, // public (pub)
        r#"(?<func>\bfunc\b)"#, // func
        r#"(?P<at_decl_with_params>@.+?\(.*?\))"#, // @decl()
        r#"(?P<at_decl>@.*)"#, // @decl
        r#"(?P<t_i32>\bi32\b)"#, // i32 (t¥ = type)
        r#"(?P<t_i64>\bi64\b)"#, // i36
        r#"(?P<t_f32>\bf32\b)"#, // f32
        r#"(?P<t_f64>\bf64\b)"#, // f64
        r#"(?P<t_string>\bString\b)"#, // String
        r#"(?P<t_array>\bArray<.*?>\b)"#, // Array<type>
        // r#"(?P<t_array>(?:(?<=: )|(?<=:))\[.*?\])"#, // Array type declaration (: [i32])
        r#"(?P<type_decl>:)"#, // type declaration (:) (needs context  -> ident_with_type_decl, ...
        r#"(?P<double_equal>==)"#, // ==
        r#"(?P<equal>=)"#, // =
        r#"(?P<array>\[.*?\])"#, // Array ([5, 6])
        r#"(?P<floating_point>\d+?.\d+?)"#, // Floating point (5.6)
        r#"(?P<int>\b\d+\b)"#, // integer (56)
        r#"(?:"(?P<string>.*?)")"#, // string ("56") // TODO: escape char
        r#"(?P<ident>\b[a-zA-Z_]+[a-zA-Z_0-9$]+\b(?!\())"#, // identifier
        r#"(?P<func_decl>(?<=func )[a-zA-Z_]+[a-zA-Z_0-9$]+\(\))"#,
        r#"(?P<function_call>[a-zA-Z_]+[a-zA-Z_0-9$]+\(\))"#,
        r#"(?<body>{(?:.*|\n*)*?})"#, // Any body ({})
        r#"(?P<regex>\/.*?\/)"#, // regex
        r#"(?P<return_a>->)"#, // return token (->)
    ].join("|")
}
