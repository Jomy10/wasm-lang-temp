use parser::parser::{Node, FuncParam};

pub fn generate_wat(nodes: Vec<Node>) -> String {
    let mut gen_source: Vec<String> = Vec::new();

    let mut nodes_iter = nodes.iter();

    while let Some(node) = nodes_iter.next() {
        match node {
            Node::Func { ext_name, int_name, public, body: _, params } => {
                gen_source.push(
                    Function::new(
                        ext_name.to_string(), 
                        int_name.to_string(), 
                        *public,
                        params.to_vec(),
                    ).build()
                );
            },
            Node::FuncParam => unreachable!("Program reached an unreachable state, please report an issue (Node::FuncParam reached in match node at line {})", line!()),
        }
    }

    return gen_source.join("")
}

/// Buildable to wat
trait Buildable {
    fn build(&self) -> String;
}


/// Represents a function in wat
struct Function<'a> {
    external_name: String,
    internal_name: String,
    is_public: bool,
    params: Vec<FuncParam<'a>>,
}

impl<'a> Function<'a> {
    pub fn new(external_name: String, internal_name: String, is_public: bool, params: Vec<FuncParam<'a>>) -> Self {
        Self { external_name, internal_name, is_public, params }
    }
    
    // `build` in case the function's name is main
    fn build_main(&self) -> String {
        let int_name = &self.internal_name;
        let export = format!("(export \"{}\" (func ${}))", self.external_name, self.internal_name);
        let export2 = format!("(export \"_start\" (func ${}))", self.internal_name);
        format!(
            "{export}{export2}(func ${int_name})"
        )
    }
}

impl Buildable for Function<'_> {
    fn build(&self) -> String {
        // Main = special export name
        if &self.external_name == "main" {
            return self.build_main();
        }
        
        // Build function
        let int_name = &self.internal_name;
        let export = if self.is_public { format!("(export \"{}\" (func ${}))", self.external_name, self.internal_name) } else { "".to_string() };
        let params: String = self.params.iter().map(|param| {
            format!("(param ${} {})", param.int_name, param.t)
        }).collect::<Vec<String>>().join("");
        format!(
            "{export}(func ${int_name} {params})"
        )
    }
}
