use criterion::{criterion_group, criterion_main, Criterion, BenchmarkId};
use parser;
use tree_sitter_wasm_lang as ts;
use tree_sitter;

const SOURCES: [&str; 5] = [
    "var m: i32 = 5",
    "func someFunc() { var m = 56788456454654 }",
    "func someFunc() -> i32 { return 69 }",
    "func someFunc(field: i32, field2: i32, field3: i32, field4: i32) -> i32 { var m: i32 = 420 return m}",
    "func someFunc(field: i32) -> i32 { return 69420 }"
];

fn bench(c: &mut Criterion) {
    let mut group = c.benchmark_group("parsers");
    for i in SOURCES.iter() {
        group.bench_with_input(BenchmarkId::new("tree_sitter", i), i, |b, i| b.iter({|| {
            let mut parser = tree_sitter::Parser::new();
            parser
                .set_language(ts::language())
                .expect("Error loading language");
    
            let tree = parser.parse(i, None).unwrap();
        }}));
        group.bench_with_input(BenchmarkId::new("custom_parser", i), i, |b, i| b.iter(|| {
            let tokens = parser::lexer::tokenize(i);
            let parsed = parser::parser::parse(&tokens, i, "main");
        }));
    }
}

criterion_group!(benches, bench);
criterion_main!(benches);
