#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 52
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 38
#define ALIAS_COUNT 0
#define TOKEN_COUNT 22
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 7
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 9

enum {
  anon_sym_func = 1,
  anon_sym_DASH_GT = 2,
  sym__empty_scope = 3,
  sym_pub = 4,
  anon_sym_LPAREN = 5,
  anon_sym_COMMA = 6,
  anon_sym_RPAREN = 7,
  sym__empty_params_decl = 8,
  sym__o_curly = 9,
  sym__c_curly = 10,
  anon_sym_var = 11,
  anon_sym_EQ = 12,
  anon_sym_return = 13,
  sym_ident = 14,
  anon_sym_i32 = 15,
  anon_sym_i64 = 16,
  anon_sym_f32 = 17,
  anon_sym_f64 = 18,
  anon_sym_Void = 19,
  anon_sym_COLON = 20,
  sym_int_literal = 21,
  sym_program = 22,
  sym_func_decl = 23,
  sym__func_type_decl = 24,
  sym_params_decl = 25,
  sym_param_decl = 26,
  sym_body = 27,
  sym_var_decl = 28,
  sym_return = 29,
  sym_type = 30,
  sym__type_decl = 31,
  sym__statement = 32,
  sym__expression = 33,
  sym__literal_val = 34,
  aux_sym_program_repeat1 = 35,
  aux_sym_params_decl_repeat1 = 36,
  aux_sym_body_repeat1 = 37,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_func] = "func",
  [anon_sym_DASH_GT] = "->",
  [sym__empty_scope] = "_empty_scope",
  [sym_pub] = "pub",
  [anon_sym_LPAREN] = "(",
  [anon_sym_COMMA] = ",",
  [anon_sym_RPAREN] = ")",
  [sym__empty_params_decl] = "_empty_params_decl",
  [sym__o_curly] = "_o_curly",
  [sym__c_curly] = "_c_curly",
  [anon_sym_var] = "var",
  [anon_sym_EQ] = "=",
  [anon_sym_return] = "return",
  [sym_ident] = "ident",
  [anon_sym_i32] = "i32",
  [anon_sym_i64] = "i64",
  [anon_sym_f32] = "f32",
  [anon_sym_f64] = "f64",
  [anon_sym_Void] = "Void",
  [anon_sym_COLON] = ":",
  [sym_int_literal] = "int_literal",
  [sym_program] = "program",
  [sym_func_decl] = "func_decl",
  [sym__func_type_decl] = "_func_type_decl",
  [sym_params_decl] = "params_decl",
  [sym_param_decl] = "param_decl",
  [sym_body] = "body",
  [sym_var_decl] = "var_decl",
  [sym_return] = "return",
  [sym_type] = "type",
  [sym__type_decl] = "_type_decl",
  [sym__statement] = "_statement",
  [sym__expression] = "_expression",
  [sym__literal_val] = "_literal_val",
  [aux_sym_program_repeat1] = "program_repeat1",
  [aux_sym_params_decl_repeat1] = "params_decl_repeat1",
  [aux_sym_body_repeat1] = "body_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_func] = anon_sym_func,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [sym__empty_scope] = sym__empty_scope,
  [sym_pub] = sym_pub,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym__empty_params_decl] = sym__empty_params_decl,
  [sym__o_curly] = sym__o_curly,
  [sym__c_curly] = sym__c_curly,
  [anon_sym_var] = anon_sym_var,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_return] = anon_sym_return,
  [sym_ident] = sym_ident,
  [anon_sym_i32] = anon_sym_i32,
  [anon_sym_i64] = anon_sym_i64,
  [anon_sym_f32] = anon_sym_f32,
  [anon_sym_f64] = anon_sym_f64,
  [anon_sym_Void] = anon_sym_Void,
  [anon_sym_COLON] = anon_sym_COLON,
  [sym_int_literal] = sym_int_literal,
  [sym_program] = sym_program,
  [sym_func_decl] = sym_func_decl,
  [sym__func_type_decl] = sym__func_type_decl,
  [sym_params_decl] = sym_params_decl,
  [sym_param_decl] = sym_param_decl,
  [sym_body] = sym_body,
  [sym_var_decl] = sym_var_decl,
  [sym_return] = sym_return,
  [sym_type] = sym_type,
  [sym__type_decl] = sym__type_decl,
  [sym__statement] = sym__statement,
  [sym__expression] = sym__expression,
  [sym__literal_val] = sym__literal_val,
  [aux_sym_program_repeat1] = aux_sym_program_repeat1,
  [aux_sym_params_decl_repeat1] = aux_sym_params_decl_repeat1,
  [aux_sym_body_repeat1] = aux_sym_body_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_func] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [sym__empty_scope] = {
    .visible = false,
    .named = true,
  },
  [sym_pub] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [sym__empty_params_decl] = {
    .visible = false,
    .named = true,
  },
  [sym__o_curly] = {
    .visible = false,
    .named = true,
  },
  [sym__c_curly] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_var] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_return] = {
    .visible = true,
    .named = false,
  },
  [sym_ident] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_i32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_i64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_f32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_f64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Void] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [sym_int_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_program] = {
    .visible = true,
    .named = true,
  },
  [sym_func_decl] = {
    .visible = true,
    .named = true,
  },
  [sym__func_type_decl] = {
    .visible = false,
    .named = true,
  },
  [sym_params_decl] = {
    .visible = true,
    .named = true,
  },
  [sym_param_decl] = {
    .visible = true,
    .named = true,
  },
  [sym_body] = {
    .visible = true,
    .named = true,
  },
  [sym_var_decl] = {
    .visible = true,
    .named = true,
  },
  [sym_return] = {
    .visible = true,
    .named = true,
  },
  [sym_type] = {
    .visible = true,
    .named = true,
  },
  [sym__type_decl] = {
    .visible = false,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym__literal_val] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_program_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_params_decl_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_body_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_body = 1,
  field_name = 2,
  field_params = 3,
  field_pub = 4,
  field_return_type = 5,
  field_type = 6,
  field_value = 7,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_body] = "body",
  [field_name] = "name",
  [field_params] = "params",
  [field_pub] = "pub",
  [field_return_type] = "return_type",
  [field_type] = "type",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 3},
  [2] = {.index = 3, .length = 2},
  [3] = {.index = 5, .length = 1},
  [4] = {.index = 6, .length = 2},
  [5] = {.index = 8, .length = 4},
  [6] = {.index = 12, .length = 4},
  [7] = {.index = 16, .length = 4},
  [8] = {.index = 20, .length = 5},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_body, 3},
    {field_name, 1},
    {field_params, 2},
  [3] =
    {field_name, 1},
    {field_value, 3},
  [5] =
    {field_type, 1},
  [6] =
    {field_name, 0},
    {field_type, 1, .inherited = true},
  [8] =
    {field_body, 4},
    {field_name, 1},
    {field_params, 2},
    {field_return_type, 3},
  [12] =
    {field_body, 4},
    {field_name, 2},
    {field_params, 3},
    {field_pub, 0},
  [16] =
    {field_name, 1},
    {field_type, 2},
    {field_type, 2, .inherited = true},
    {field_value, 4},
  [20] =
    {field_body, 5},
    {field_name, 2},
    {field_params, 3},
    {field_pub, 0},
    {field_return_type, 4},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(24);
      if (lookahead == '(') ADVANCE(29);
      if (lookahead == ')') ADVANCE(31);
      if (lookahead == ',') ADVANCE(30);
      if (lookahead == '-') ADVANCE(8);
      if (lookahead == ':') ADVANCE(45);
      if (lookahead == '=') ADVANCE(36);
      if (lookahead == 'V') ADVANCE(17);
      if (lookahead == 'f') ADVANCE(4);
      if (lookahead == 'i') ADVANCE(5);
      if (lookahead == 'p') ADVANCE(21);
      if (lookahead == 'r') ADVANCE(13);
      if (lookahead == 'v') ADVANCE(9);
      if (lookahead == '{') ADVANCE(33);
      if (lookahead == '}') ADVANCE(34);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(46);
      END_STATE();
    case 1:
      if (lookahead == ')') ADVANCE(31);
      if (lookahead == ',') ADVANCE(30);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(46);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(38);
      END_STATE();
    case 2:
      if (lookahead == '2') ADVANCE(42);
      END_STATE();
    case 3:
      if (lookahead == '2') ADVANCE(40);
      END_STATE();
    case 4:
      if (lookahead == '3') ADVANCE(2);
      if (lookahead == '6') ADVANCE(6);
      if (lookahead == 'u') ADVANCE(15);
      END_STATE();
    case 5:
      if (lookahead == '3') ADVANCE(3);
      if (lookahead == '6') ADVANCE(7);
      END_STATE();
    case 6:
      if (lookahead == '4') ADVANCE(43);
      END_STATE();
    case 7:
      if (lookahead == '4') ADVANCE(41);
      END_STATE();
    case 8:
      if (lookahead == '>') ADVANCE(26);
      END_STATE();
    case 9:
      if (lookahead == 'a') ADVANCE(18);
      END_STATE();
    case 10:
      if (lookahead == 'b') ADVANCE(28);
      END_STATE();
    case 11:
      if (lookahead == 'c') ADVANCE(25);
      END_STATE();
    case 12:
      if (lookahead == 'd') ADVANCE(44);
      END_STATE();
    case 13:
      if (lookahead == 'e') ADVANCE(20);
      END_STATE();
    case 14:
      if (lookahead == 'i') ADVANCE(12);
      END_STATE();
    case 15:
      if (lookahead == 'n') ADVANCE(11);
      END_STATE();
    case 16:
      if (lookahead == 'n') ADVANCE(37);
      END_STATE();
    case 17:
      if (lookahead == 'o') ADVANCE(14);
      END_STATE();
    case 18:
      if (lookahead == 'r') ADVANCE(35);
      END_STATE();
    case 19:
      if (lookahead == 'r') ADVANCE(16);
      END_STATE();
    case 20:
      if (lookahead == 't') ADVANCE(22);
      END_STATE();
    case 21:
      if (lookahead == 'u') ADVANCE(10);
      END_STATE();
    case 22:
      if (lookahead == 'u') ADVANCE(19);
      END_STATE();
    case 23:
      if (lookahead == '}') ADVANCE(27);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(23);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_func);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym__empty_scope);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_pub);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      if (lookahead == ')') ADVANCE(32);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym__empty_params_decl);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym__o_curly);
      if (lookahead == '}') ADVANCE(27);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(23);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym__c_curly);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_var);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_return);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(39);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(38);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(39);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_i32);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_i64);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_f32);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_f64);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_Void);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_int_literal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(46);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 1},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 1},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 1},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 1},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 1},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 1},
  [45] = {.lex_state = 1},
  [46] = {.lex_state = 1},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 1},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_func] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [sym__empty_scope] = ACTIONS(1),
    [sym_pub] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym__empty_params_decl] = ACTIONS(1),
    [sym__o_curly] = ACTIONS(1),
    [sym__c_curly] = ACTIONS(1),
    [anon_sym_var] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_return] = ACTIONS(1),
    [anon_sym_i32] = ACTIONS(1),
    [anon_sym_i64] = ACTIONS(1),
    [anon_sym_f32] = ACTIONS(1),
    [anon_sym_f64] = ACTIONS(1),
    [anon_sym_Void] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [sym_int_literal] = ACTIONS(1),
  },
  [1] = {
    [sym_program] = STATE(47),
    [sym_func_decl] = STATE(4),
    [sym_var_decl] = STATE(4),
    [aux_sym_program_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_func] = ACTIONS(5),
    [sym_pub] = ACTIONS(7),
    [anon_sym_var] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(11), 1,
      sym__c_curly,
    ACTIONS(13), 1,
      anon_sym_var,
    ACTIONS(16), 1,
      anon_sym_return,
    STATE(2), 4,
      sym_var_decl,
      sym_return,
      sym__statement,
      aux_sym_body_repeat1,
  [16] = 4,
    ACTIONS(9), 1,
      anon_sym_var,
    ACTIONS(19), 1,
      sym__c_curly,
    ACTIONS(21), 1,
      anon_sym_return,
    STATE(2), 4,
      sym_var_decl,
      sym_return,
      sym__statement,
      aux_sym_body_repeat1,
  [32] = 5,
    ACTIONS(5), 1,
      anon_sym_func,
    ACTIONS(7), 1,
      sym_pub,
    ACTIONS(9), 1,
      anon_sym_var,
    ACTIONS(23), 1,
      ts_builtin_sym_end,
    STATE(5), 3,
      sym_func_decl,
      sym_var_decl,
      aux_sym_program_repeat1,
  [50] = 5,
    ACTIONS(25), 1,
      ts_builtin_sym_end,
    ACTIONS(27), 1,
      anon_sym_func,
    ACTIONS(30), 1,
      sym_pub,
    ACTIONS(33), 1,
      anon_sym_var,
    STATE(5), 3,
      sym_func_decl,
      sym_var_decl,
      aux_sym_program_repeat1,
  [68] = 4,
    ACTIONS(9), 1,
      anon_sym_var,
    ACTIONS(21), 1,
      anon_sym_return,
    ACTIONS(36), 1,
      sym__c_curly,
    STATE(3), 4,
      sym_var_decl,
      sym_return,
      sym__statement,
      aux_sym_body_repeat1,
  [84] = 1,
    ACTIONS(38), 6,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      sym__c_curly,
      anon_sym_var,
      anon_sym_return,
  [93] = 1,
    ACTIONS(40), 6,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      sym__c_curly,
      anon_sym_var,
      anon_sym_return,
  [102] = 2,
    STATE(29), 1,
      sym_type,
    ACTIONS(42), 5,
      anon_sym_i32,
      anon_sym_i64,
      anon_sym_f32,
      anon_sym_f64,
      anon_sym_Void,
  [113] = 2,
    STATE(42), 1,
      sym_type,
    ACTIONS(42), 5,
      anon_sym_i32,
      anon_sym_i64,
      anon_sym_f32,
      anon_sym_f64,
      anon_sym_Void,
  [124] = 2,
    ACTIONS(46), 1,
      sym__o_curly,
    ACTIONS(44), 4,
      sym__empty_scope,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_EQ,
  [134] = 5,
    ACTIONS(48), 1,
      anon_sym_DASH_GT,
    ACTIONS(50), 1,
      sym__empty_scope,
    ACTIONS(52), 1,
      sym__o_curly,
    STATE(19), 1,
      sym_body,
    STATE(39), 1,
      sym__func_type_decl,
  [150] = 5,
    ACTIONS(48), 1,
      anon_sym_DASH_GT,
    ACTIONS(52), 1,
      sym__o_curly,
    ACTIONS(54), 1,
      sym__empty_scope,
    STATE(23), 1,
      sym_body,
    STATE(37), 1,
      sym__func_type_decl,
  [166] = 2,
    ACTIONS(56), 2,
      sym_ident,
      sym_int_literal,
    STATE(8), 2,
      sym__expression,
      sym__literal_val,
  [175] = 2,
    ACTIONS(58), 2,
      sym_ident,
      sym_int_literal,
    STATE(7), 2,
      sym__expression,
      sym__literal_val,
  [184] = 4,
    ACTIONS(60), 1,
      anon_sym_COMMA,
    ACTIONS(62), 1,
      anon_sym_RPAREN,
    ACTIONS(64), 1,
      sym_ident,
    STATE(36), 1,
      sym_param_decl,
  [197] = 1,
    ACTIONS(66), 4,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      anon_sym_var,
  [204] = 1,
    ACTIONS(68), 4,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      anon_sym_var,
  [211] = 1,
    ACTIONS(70), 4,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      anon_sym_var,
  [218] = 1,
    ACTIONS(72), 4,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      anon_sym_var,
  [225] = 2,
    ACTIONS(74), 2,
      sym_ident,
      sym_int_literal,
    STATE(27), 2,
      sym__expression,
      sym__literal_val,
  [234] = 1,
    ACTIONS(76), 4,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      anon_sym_var,
  [241] = 1,
    ACTIONS(78), 4,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      anon_sym_var,
  [248] = 3,
    ACTIONS(80), 1,
      anon_sym_COMMA,
    ACTIONS(82), 1,
      anon_sym_RPAREN,
    STATE(31), 1,
      aux_sym_params_decl_repeat1,
  [258] = 2,
    ACTIONS(86), 1,
      sym__o_curly,
    ACTIONS(84), 2,
      anon_sym_DASH_GT,
      sym__empty_scope,
  [266] = 2,
    ACTIONS(90), 1,
      sym__o_curly,
    ACTIONS(88), 2,
      anon_sym_DASH_GT,
      sym__empty_scope,
  [274] = 1,
    ACTIONS(92), 3,
      sym__c_curly,
      anon_sym_var,
      anon_sym_return,
  [280] = 3,
    ACTIONS(94), 1,
      anon_sym_LPAREN,
    ACTIONS(96), 1,
      sym__empty_params_decl,
    STATE(13), 1,
      sym_params_decl,
  [290] = 1,
    ACTIONS(98), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_EQ,
  [296] = 2,
    ACTIONS(102), 1,
      sym__o_curly,
    ACTIONS(100), 2,
      anon_sym_DASH_GT,
      sym__empty_scope,
  [304] = 3,
    ACTIONS(104), 1,
      anon_sym_COMMA,
    ACTIONS(107), 1,
      anon_sym_RPAREN,
    STATE(31), 1,
      aux_sym_params_decl_repeat1,
  [314] = 3,
    ACTIONS(64), 1,
      sym_ident,
    ACTIONS(82), 1,
      anon_sym_RPAREN,
    STATE(40), 1,
      sym_param_decl,
  [324] = 3,
    ACTIONS(109), 1,
      anon_sym_EQ,
    ACTIONS(111), 1,
      anon_sym_COLON,
    STATE(50), 1,
      sym__type_decl,
  [334] = 3,
    ACTIONS(64), 1,
      sym_ident,
    ACTIONS(113), 1,
      anon_sym_RPAREN,
    STATE(40), 1,
      sym_param_decl,
  [344] = 3,
    ACTIONS(94), 1,
      anon_sym_LPAREN,
    ACTIONS(115), 1,
      sym__empty_params_decl,
    STATE(12), 1,
      sym_params_decl,
  [354] = 3,
    ACTIONS(117), 1,
      anon_sym_COMMA,
    ACTIONS(119), 1,
      anon_sym_RPAREN,
    STATE(24), 1,
      aux_sym_params_decl_repeat1,
  [364] = 3,
    ACTIONS(52), 1,
      sym__o_curly,
    ACTIONS(121), 1,
      sym__empty_scope,
    STATE(20), 1,
      sym_body,
  [374] = 2,
    ACTIONS(125), 1,
      sym__o_curly,
    ACTIONS(123), 2,
      anon_sym_DASH_GT,
      sym__empty_scope,
  [382] = 3,
    ACTIONS(52), 1,
      sym__o_curly,
    ACTIONS(127), 1,
      sym__empty_scope,
    STATE(17), 1,
      sym_body,
  [392] = 1,
    ACTIONS(107), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [397] = 2,
    ACTIONS(111), 1,
      anon_sym_COLON,
    STATE(43), 1,
      sym__type_decl,
  [404] = 2,
    ACTIONS(129), 1,
      sym__empty_scope,
    ACTIONS(131), 1,
      sym__o_curly,
  [411] = 1,
    ACTIONS(133), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [416] = 2,
    ACTIONS(64), 1,
      sym_ident,
    STATE(40), 1,
      sym_param_decl,
  [423] = 1,
    ACTIONS(135), 1,
      sym_ident,
  [427] = 1,
    ACTIONS(137), 1,
      sym_ident,
  [431] = 1,
    ACTIONS(139), 1,
      ts_builtin_sym_end,
  [435] = 1,
    ACTIONS(119), 1,
      anon_sym_RPAREN,
  [439] = 1,
    ACTIONS(141), 1,
      anon_sym_func,
  [443] = 1,
    ACTIONS(143), 1,
      anon_sym_EQ,
  [447] = 1,
    ACTIONS(145), 1,
      sym_ident,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 16,
  [SMALL_STATE(4)] = 32,
  [SMALL_STATE(5)] = 50,
  [SMALL_STATE(6)] = 68,
  [SMALL_STATE(7)] = 84,
  [SMALL_STATE(8)] = 93,
  [SMALL_STATE(9)] = 102,
  [SMALL_STATE(10)] = 113,
  [SMALL_STATE(11)] = 124,
  [SMALL_STATE(12)] = 134,
  [SMALL_STATE(13)] = 150,
  [SMALL_STATE(14)] = 166,
  [SMALL_STATE(15)] = 175,
  [SMALL_STATE(16)] = 184,
  [SMALL_STATE(17)] = 197,
  [SMALL_STATE(18)] = 204,
  [SMALL_STATE(19)] = 211,
  [SMALL_STATE(20)] = 218,
  [SMALL_STATE(21)] = 225,
  [SMALL_STATE(22)] = 234,
  [SMALL_STATE(23)] = 241,
  [SMALL_STATE(24)] = 248,
  [SMALL_STATE(25)] = 258,
  [SMALL_STATE(26)] = 266,
  [SMALL_STATE(27)] = 274,
  [SMALL_STATE(28)] = 280,
  [SMALL_STATE(29)] = 290,
  [SMALL_STATE(30)] = 296,
  [SMALL_STATE(31)] = 304,
  [SMALL_STATE(32)] = 314,
  [SMALL_STATE(33)] = 324,
  [SMALL_STATE(34)] = 334,
  [SMALL_STATE(35)] = 344,
  [SMALL_STATE(36)] = 354,
  [SMALL_STATE(37)] = 364,
  [SMALL_STATE(38)] = 374,
  [SMALL_STATE(39)] = 382,
  [SMALL_STATE(40)] = 392,
  [SMALL_STATE(41)] = 397,
  [SMALL_STATE(42)] = 404,
  [SMALL_STATE(43)] = 411,
  [SMALL_STATE(44)] = 416,
  [SMALL_STATE(45)] = 423,
  [SMALL_STATE(46)] = 427,
  [SMALL_STATE(47)] = 431,
  [SMALL_STATE(48)] = 435,
  [SMALL_STATE(49)] = 439,
  [SMALL_STATE(50)] = 443,
  [SMALL_STATE(51)] = 447,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_body_repeat1, 2),
  [13] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_body_repeat1, 2), SHIFT_REPEAT(45),
  [16] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_body_repeat1, 2), SHIFT_REPEAT(21),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 1),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2),
  [27] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(46),
  [30] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(49),
  [33] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(45),
  [36] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [38] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_decl, 5, .production_id = 7),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_decl, 4, .production_id = 2),
  [42] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [46] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type, 1),
  [48] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [52] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [60] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_decl, 6, .production_id = 8),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_body, 3),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_decl, 5, .production_id = 6),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_decl, 5, .production_id = 5),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_body, 2),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_decl, 4, .production_id = 1),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_params_decl, 4),
  [86] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_params_decl, 4),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_params_decl, 5),
  [90] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_params_decl, 5),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return, 2),
  [94] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [96] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__type_decl, 2, .production_id = 3),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_params_decl, 3),
  [102] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_params_decl, 3),
  [104] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_params_decl_repeat1, 2), SHIFT_REPEAT(44),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_params_decl_repeat1, 2),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_params_decl, 2),
  [125] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_params_decl, 2),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__func_type_decl, 2),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__func_type_decl, 2),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_param_decl, 2, .production_id = 4),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [139] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_wasm_lang(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
