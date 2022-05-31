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
    _func_type_decl: $ => seq($._arrow_token, $.type),
    _arrow_token: _ => token('->'),
    _empty_scope: _ => /\{\s*\}/,
    pub: _ => token('pub'),
    
    params_decl: $ => seq($._o_paren, sepBy($._comma, $.param_decl), optional($._comma), $._c_paren),
    param_decl: $ => seq(field('name', $.ident), $._type_decl),
    _empty_params_decl: _ => '()',

    body: $ => seq($._o_curly, repeat($._statement), $._c_curly),
    _o_curly: _ => token('{'),
    _c_curly: _ => token('}'),
    _o_paren: _ => token('('),
    _c_paren: _ => token(')'),
    _colon: _ => token(':'),
    _comma: _ => token(','),
    
    var_decl: $ => seq(
      token('var'),
      field('name', $.ident),
      field('type', optional($._type_decl)),
      token('='),
      field('value', $._expression),
    ),
    
    return: $ => seq($._return_token, optional(field('value', $._expression))),
    _return_token: _ => token('return'),
    
    ident: _ => /[a-zA-Z_]+[a-zA-Z_0-9$]*/,
    
    type: _ => choice('i32', 'i64', 'f32', 'f64', 'Void'),
    _type_decl: $ => seq($._colon, field ('type', $.type)),
    
    // Standalone unit of execution, doesn't return anything
    _statement: $ => choice(
      $.return,
      $.var_decl,
    ),
    
    // An expression returns a value. This will always be a single node
    _expression: $ => choice(
      $._literal_val,
      $.ident,
      $.unary_expr,
      $.binary_expr,
      $._expr_with_paren,
    ),
    
    _expr_with_paren: $ => prec(3, seq($._o_paren, $._expression, $._c_paren)),
    
    unary_expr: $ => prec(4, choice(
      seq(token('-'), $._expression),
      // seq(token('!'), $._expression),
    )),
     
    binary_expr: $ => choice(
      prec.left(2, seq($._expression, token('*'), $._expression)),
      prec.left(2, seq($._expression, token('/'), $._expression)),
      prec.left(1, seq($._expression, token('+'), $._expression)),
      prec.left(1, seq($._expression, token('-'), $._expression)),
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
