# Specification

<!-- We follow the following BNF specification: https://www.w3.org/Notation.html -->
```bnf
;; tokens
<pub> ::= pub
<func> ::= func
<var> ::= var
<return> ::= return
<int_literal> ::= *DIGIT
<type_i32> ::= i32
<type_i63> ::= i64
<type_f32> ::= f32
<type_f64> ::= f64
<type> ::= (type_i32 | type_i64 | type_f32 | type_f64)
<ident> ::= 1*(ALPHA | _) | *1(ALPHA | _)*(ALPHA | _ | DIGIT | $)

;; Nodes
<expression> ::= ;; TODO
<var_decl> ::= var ident[: type] = expression
<return_stmt> ::= return expression
<func_def> ::= func ident\(0#(ident: type)\) {
  0*expression
}
```
