module.exports = grammar({
  name: "wasm_lang",
  
  externals: $ => [
    // $.eight,
  ],
  
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
      field('params', choice($.params_decl, $._empty_params_decl)),
      field('return_type', optional($._func_type_decl)),
      field('body', choice($._empty_scope, $.body)),
    ),
    _func_type_decl: $ => seq('->', $.type),
    _empty_scope: _ => /\{\s*\}/,
    pub: _ => token('pub'),
    
    params_decl: $ => seq('(', sepBy(',', $.param_decl), optional(','), ')'),
    param_decl: $ => seq(field('name', $.ident), $._type_decl),
    _empty_params_decl: _ => '()',

    body: $ => seq($._o_curly, repeat($._statement), $._c_curly),
    _o_curly: _ => token('{'),
    _c_curly: _ => token('}'),
    
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
    _type_decl: $ => seq(':', field ('type', $.type)),
    
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
