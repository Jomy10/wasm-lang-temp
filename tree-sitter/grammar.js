module.exports = grammar({
  name: "wasm_lang",
  
  rules: {
    program: $ => repeat(choice(
      // Can be in the global scope
      $.func_decl,
      $.var_decl
    )),
    
    func_decl: $ => seq(
      field("pub", optional($.pub)),
      token('func'),
      field('name', $.ident),
      field('params', choice($.params_decl, "()")),
      field('return_type', optional($._func_type_decl)),
      field('body', choice(/\{\s*\}/, $.body)),
    ),
    _func_type_decl: $ => seq('->', $.type),
    pub: _ => token('pub'),
    
    params_decl: $ => seq('(', sepBy(',', $.param_decl), optional(','), ')'),
    param_decl: $ => seq($.ident, $._type_decl),

    body: $ => seq('{', repeat($._statement), '}'), // TODO 
    
    // TODO: infer type
    var_decl: $ => seq(
      token('var'),
      field('name', $.ident),
      field('type', optional($._type_decl)),
      token('='),
      field('value', $._expression),
    ),
    
    return: $ => seq(token('return'), $._expression),
    
    ident: _ => /[a-zA-Z_]+[a-zA-Z_0-9$]*/,
    
    type: _ => choice('i32', 'i64', 'f32', 'f64', 'Void'),
    _type_decl: $ => seq(':', $.type),
    
    // Standalone unit of execution, doesn't return anything
    _statement: $ => choice(
      $.return,
      $.var_decl,
    ),
    
    // An expression returns a value. This will always be a single node
    _expression: $ => choice(
      $._literal_val,
      $.ident
    ),
    
    // literals //
    _literal_val: $ => choice(
      $.int_literal,
    ),
    int_literal: _ => /\d+/,
  }
});

// ==============================
// Helper functions
// ==============================
function sepBy1(sep, rule) {
  return seq(rule, repeat(seq(sep, rule)))
}

function sepBy(sep, rule) {
  return optional(sepBy1(sep, rule))
}
