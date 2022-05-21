use fancy_regex::Regex;
use lazy_static::lazy_static;

lazy_static! {
    static ref REGEX: Regex = Regex::new(&parser_regex()).unwrap();
}

/// Tokenize source code into `Tokens` using regex (see `parser_regex`)
pub fn tokenize(input: &str) -> Vec<Token> {
    let group_names: Vec<&str> = REGEX.capture_names().skip(1).map(|x| x.unwrap()).collect::<Vec<&str>>();
    
    let mut matches: Vec<Token> = vec![];
    for captures in REGEX.captures_iter(input) {
        for name in &group_names {
            if let Some(m) = captures.as_ref().unwrap().name(name) {
                matches.push(Token::new(name, (m.start(), m.end())));
            }
        }
    }
    
    matches
}

#[derive(Debug, PartialEq)]
pub struct Token<'a> {
    pub name: &'a str,
    pub range: (usize, usize)
}

impl<'a> Token<'a> {
    pub fn new(name: &'a str, range: (usize, usize)) -> Self {
        Self {
            name, range
        }
    }
    
    pub fn from(tuple: (&'a str, (usize, usize))) -> Self {
        Self {
            name: tuple.0,
            range: tuple.1
        }
    }
}

// TODO: join string at compile time
fn parser_regex() -> String {
    [
        r#"(?<pub>\bpub\b)"#,                               // pub
        r#"(?<func>\bfunc\b)"#,                             // func
        r#"(?<var>\bvar\b)"#,                               // var
        r#"(?<return>\breturn\b)"#,                         // return
        r#"(?<int_literal>\b\d+\b)"#,                       // integer literal; `56`, `7`
        r#"(?<equal_sign>=)"#,                              // =
        r#"(?<open_bracket>\()"#,                           // (
        r#"(?<closed_bracket>\))"#,                         // )
        r#"(?<open_curly_bracket>\{)"#,                     // {
        r#"(?<closed_curly_bracket>\})"#,                   // }
        r#"(?<colon>:)"#,                                   // :
        r#"(?<comma>,)"#,                                   // ,
        r#"(?<type>\b(?:i32|i64|f32|f64)\b)"#,              // types (i32, i64, f32, f64)
        r#"(?<ident>\b[a-zA-Z_]+[a-zA-Z_0-9$]*\b)"#,        // identifier (someIdent, some$ident, $notIdent, _someIdent)
    ].join("|")
}

/*
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
        r#"(?P<t_i32>\bi32\b)"#, // i32 (t = type)
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
*/
