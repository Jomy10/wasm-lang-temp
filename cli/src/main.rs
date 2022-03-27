// NOT FUNCTIONAL

use lexer::tokenize;

fn main() {
    let input = r#"
    import std
    
    // Comment
    var test = 5
    /// Doc comment
    pub let _var = 4
    
    // implementation is from a wat file
    @deprecated
    @available(package: 1.0)
    @available(lang_name: 1.5)
    @available(package: 1.0, lang_name: 1.5)
    @_wat("file.wat")
    func test() -> i32
    "#;
    
    println!("{:?}", tokenize(input));
}
