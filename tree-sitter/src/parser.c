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
#define PRODUCTION_ID_COUNT 10

enum {
  anon_sym_func = 1,
  sym__arrow_token = 2,
  sym__empty_scope = 3,
  sym_pub = 4,
  sym__empty_params_decl = 5,
  sym__o_curly = 6,
  sym__c_curly = 7,
  sym__o_brack = 8,
  sym__c_brack = 9,
  sym__colon = 10,
  sym__comma = 11,
  anon_sym_var = 12,
  anon_sym_EQ = 13,
  sym__return_token = 14,
  sym_ident = 15,
  anon_sym_i32 = 16,
  anon_sym_i64 = 17,
  anon_sym_f32 = 18,
  anon_sym_f64 = 19,
  anon_sym_Void = 20,
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
  [sym__arrow_token] = "_arrow_token",
  [sym__empty_scope] = "_empty_scope",
  [sym_pub] = "pub",
  [sym__empty_params_decl] = "_empty_params_decl",
  [sym__o_curly] = "_o_curly",
  [sym__c_curly] = "_c_curly",
  [sym__o_brack] = "_o_brack",
  [sym__c_brack] = "_c_brack",
  [sym__colon] = "_colon",
  [sym__comma] = "_comma",
  [anon_sym_var] = "var",
  [anon_sym_EQ] = "=",
  [sym__return_token] = "_return_token",
  [sym_ident] = "ident",
  [anon_sym_i32] = "i32",
  [anon_sym_i64] = "i64",
  [anon_sym_f32] = "f32",
  [anon_sym_f64] = "f64",
  [anon_sym_Void] = "Void",
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
  [sym__arrow_token] = sym__arrow_token,
  [sym__empty_scope] = sym__empty_scope,
  [sym_pub] = sym_pub,
  [sym__empty_params_decl] = sym__empty_params_decl,
  [sym__o_curly] = sym__o_curly,
  [sym__c_curly] = sym__c_curly,
  [sym__o_brack] = sym__o_brack,
  [sym__c_brack] = sym__c_brack,
  [sym__colon] = sym__colon,
  [sym__comma] = sym__comma,
  [anon_sym_var] = anon_sym_var,
  [anon_sym_EQ] = anon_sym_EQ,
  [sym__return_token] = sym__return_token,
  [sym_ident] = sym_ident,
  [anon_sym_i32] = anon_sym_i32,
  [anon_sym_i64] = anon_sym_i64,
  [anon_sym_f32] = anon_sym_f32,
  [anon_sym_f64] = anon_sym_f64,
  [anon_sym_Void] = anon_sym_Void,
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
  [sym__arrow_token] = {
    .visible = false,
    .named = true,
  },
  [sym__empty_scope] = {
    .visible = false,
    .named = true,
  },
  [sym_pub] = {
    .visible = true,
    .named = true,
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
  [sym__o_brack] = {
    .visible = false,
    .named = true,
  },
  [sym__c_brack] = {
    .visible = false,
    .named = true,
  },
  [sym__colon] = {
    .visible = false,
    .named = true,
  },
  [sym__comma] = {
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
  [sym__return_token] = {
    .visible = false,
    .named = true,
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
  [2] = {.index = 3, .length = 1},
  [3] = {.index = 4, .length = 2},
  [4] = {.index = 6, .length = 4},
  [5] = {.index = 10, .length = 2},
  [6] = {.index = 12, .length = 4},
  [7] = {.index = 16, .length = 4},
  [8] = {.index = 20, .length = 1},
  [9] = {.index = 21, .length = 5},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_body, 3},
    {field_name, 1},
    {field_params, 2},
  [3] =
    {field_type, 1},
  [4] =
    {field_name, 1},
    {field_value, 3},
  [6] =
    {field_body, 4},
    {field_name, 1},
    {field_params, 2},
    {field_return_type, 3},
  [10] =
    {field_name, 0},
    {field_type, 1, .inherited = true},
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
    {field_value, 1},
  [21] =
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
      if (eof) ADVANCE(25);
      if (lookahead == '(') ADVANCE(33);
      if (lookahead == ')') ADVANCE(34);
      if (lookahead == ',') ADVANCE(36);
      if (lookahead == '-') ADVANCE(8);
      if (lookahead == ':') ADVANCE(35);
      if (lookahead == '=') ADVANCE(39);
      if (lookahead == 'V') ADVANCE(17);
      if (lookahead == 'f') ADVANCE(4);
      if (lookahead == 'i') ADVANCE(5);
      if (lookahead == 'p') ADVANCE(22);
      if (lookahead == 'r') ADVANCE(13);
      if (lookahead == 'v') ADVANCE(9);
      if (lookahead == '{') ADVANCE(31);
      if (lookahead == '}') ADVANCE(32);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(56);
      END_STATE();
    case 1:
      if (lookahead == ')') ADVANCE(34);
      if (lookahead == ',') ADVANCE(36);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(56);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(49);
      END_STATE();
    case 2:
      if (lookahead == '2') ADVANCE(53);
      END_STATE();
    case 3:
      if (lookahead == '2') ADVANCE(51);
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
      if (lookahead == '4') ADVANCE(54);
      END_STATE();
    case 7:
      if (lookahead == '4') ADVANCE(52);
      END_STATE();
    case 8:
      if (lookahead == '>') ADVANCE(27);
      END_STATE();
    case 9:
      if (lookahead == 'a') ADVANCE(18);
      END_STATE();
    case 10:
      if (lookahead == 'b') ADVANCE(29);
      END_STATE();
    case 11:
      if (lookahead == 'c') ADVANCE(26);
      END_STATE();
    case 12:
      if (lookahead == 'd') ADVANCE(55);
      END_STATE();
    case 13:
      if (lookahead == 'e') ADVANCE(21);
      END_STATE();
    case 14:
      if (lookahead == 'i') ADVANCE(12);
      END_STATE();
    case 15:
      if (lookahead == 'n') ADVANCE(11);
      END_STATE();
    case 16:
      if (lookahead == 'n') ADVANCE(40);
      END_STATE();
    case 17:
      if (lookahead == 'o') ADVANCE(14);
      END_STATE();
    case 18:
      if (lookahead == 'r') ADVANCE(37);
      END_STATE();
    case 19:
      if (lookahead == 'r') ADVANCE(43);
      if (lookahead == 'v') ADVANCE(42);
      if (lookahead == '}') ADVANCE(32);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(19)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(56);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(49);
      END_STATE();
    case 20:
      if (lookahead == 'r') ADVANCE(16);
      END_STATE();
    case 21:
      if (lookahead == 't') ADVANCE(23);
      END_STATE();
    case 22:
      if (lookahead == 'u') ADVANCE(10);
      END_STATE();
    case 23:
      if (lookahead == 'u') ADVANCE(20);
      END_STATE();
    case 24:
      if (lookahead == '}') ADVANCE(28);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(24);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_func);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym__arrow_token);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym__empty_scope);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_pub);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym__empty_params_decl);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym__o_curly);
      if (lookahead == '}') ADVANCE(28);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(24);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym__c_curly);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym__o_brack);
      if (lookahead == ')') ADVANCE(30);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym__c_brack);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym__colon);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym__comma);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_var);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_var);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(50);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(49);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym__return_token);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym__return_token);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(50);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(49);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'a') ADVANCE(45);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(50);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(49);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'e') ADVANCE(47);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(50);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(49);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'n') ADVANCE(41);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(50);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(49);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'r') ADVANCE(38);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(50);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(49);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'r') ADVANCE(44);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(50);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(49);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 't') ADVANCE(48);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(50);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(49);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'u') ADVANCE(46);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(50);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(49);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(50);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(49);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(50);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_i32);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_i64);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_f32);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_f64);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_Void);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_int_literal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(56);
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
  [4] = {.lex_state = 19},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 1},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 1},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 1},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
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
    [sym__arrow_token] = ACTIONS(1),
    [sym__empty_scope] = ACTIONS(1),
    [sym_pub] = ACTIONS(1),
    [sym__empty_params_decl] = ACTIONS(1),
    [sym__o_curly] = ACTIONS(1),
    [sym__c_curly] = ACTIONS(1),
    [sym__o_brack] = ACTIONS(1),
    [sym__c_brack] = ACTIONS(1),
    [sym__colon] = ACTIONS(1),
    [sym__comma] = ACTIONS(1),
    [anon_sym_var] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [sym__return_token] = ACTIONS(1),
    [anon_sym_i32] = ACTIONS(1),
    [anon_sym_i64] = ACTIONS(1),
    [anon_sym_f32] = ACTIONS(1),
    [anon_sym_f64] = ACTIONS(1),
    [anon_sym_Void] = ACTIONS(1),
    [sym_int_literal] = ACTIONS(1),
  },
  [1] = {
    [sym_program] = STATE(48),
    [sym_func_decl] = STATE(5),
    [sym_var_decl] = STATE(5),
    [aux_sym_program_repeat1] = STATE(5),
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
      sym__return_token,
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
      sym__return_token,
    STATE(2), 4,
      sym_var_decl,
      sym_return,
      sym__statement,
      aux_sym_body_repeat1,
  [32] = 5,
    ACTIONS(23), 1,
      sym__c_curly,
    ACTIONS(27), 1,
      sym_ident,
    ACTIONS(29), 1,
      sym_int_literal,
    ACTIONS(25), 2,
      anon_sym_var,
      sym__return_token,
    STATE(36), 2,
      sym__expression,
      sym__literal_val,
  [50] = 5,
    ACTIONS(5), 1,
      anon_sym_func,
    ACTIONS(7), 1,
      sym_pub,
    ACTIONS(9), 1,
      anon_sym_var,
    ACTIONS(31), 1,
      ts_builtin_sym_end,
    STATE(6), 3,
      sym_func_decl,
      sym_var_decl,
      aux_sym_program_repeat1,
  [68] = 5,
    ACTIONS(33), 1,
      ts_builtin_sym_end,
    ACTIONS(35), 1,
      anon_sym_func,
    ACTIONS(38), 1,
      sym_pub,
    ACTIONS(41), 1,
      anon_sym_var,
    STATE(6), 3,
      sym_func_decl,
      sym_var_decl,
      aux_sym_program_repeat1,
  [86] = 4,
    ACTIONS(9), 1,
      anon_sym_var,
    ACTIONS(21), 1,
      sym__return_token,
    ACTIONS(44), 1,
      sym__c_curly,
    STATE(3), 4,
      sym_var_decl,
      sym_return,
      sym__statement,
      aux_sym_body_repeat1,
  [102] = 2,
    STATE(41), 1,
      sym_type,
    ACTIONS(46), 5,
      anon_sym_i32,
      anon_sym_i64,
      anon_sym_f32,
      anon_sym_f64,
      anon_sym_Void,
  [113] = 1,
    ACTIONS(48), 6,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      sym__c_curly,
      anon_sym_var,
      sym__return_token,
  [122] = 1,
    ACTIONS(50), 6,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      sym__c_curly,
      anon_sym_var,
      sym__return_token,
  [131] = 2,
    STATE(27), 1,
      sym_type,
    ACTIONS(46), 5,
      anon_sym_i32,
      anon_sym_i64,
      anon_sym_f32,
      anon_sym_f64,
      anon_sym_Void,
  [142] = 2,
    ACTIONS(54), 1,
      sym__o_curly,
    ACTIONS(52), 4,
      sym__empty_scope,
      sym__c_brack,
      sym__comma,
      anon_sym_EQ,
  [152] = 5,
    ACTIONS(56), 1,
      sym__arrow_token,
    ACTIONS(58), 1,
      sym__empty_scope,
    ACTIONS(60), 1,
      sym__o_curly,
    STATE(20), 1,
      sym_body,
    STATE(38), 1,
      sym__func_type_decl,
  [168] = 5,
    ACTIONS(56), 1,
      sym__arrow_token,
    ACTIONS(60), 1,
      sym__o_curly,
    ACTIONS(62), 1,
      sym__empty_scope,
    STATE(19), 1,
      sym_body,
    STATE(39), 1,
      sym__func_type_decl,
  [184] = 4,
    ACTIONS(64), 1,
      sym__c_brack,
    ACTIONS(66), 1,
      sym__comma,
    ACTIONS(68), 1,
      sym_ident,
    STATE(31), 1,
      sym_param_decl,
  [197] = 1,
    ACTIONS(70), 4,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      anon_sym_var,
  [204] = 2,
    ACTIONS(72), 2,
      sym_ident,
      sym_int_literal,
    STATE(10), 2,
      sym__expression,
      sym__literal_val,
  [213] = 1,
    ACTIONS(74), 4,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      anon_sym_var,
  [220] = 1,
    ACTIONS(76), 4,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      anon_sym_var,
  [227] = 1,
    ACTIONS(78), 4,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      anon_sym_var,
  [234] = 1,
    ACTIONS(80), 4,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      anon_sym_var,
  [241] = 1,
    ACTIONS(82), 4,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      anon_sym_var,
  [248] = 2,
    ACTIONS(84), 2,
      sym_ident,
      sym_int_literal,
    STATE(9), 2,
      sym__expression,
      sym__literal_val,
  [257] = 2,
    ACTIONS(88), 1,
      sym__o_curly,
    ACTIONS(86), 2,
      sym__arrow_token,
      sym__empty_scope,
  [265] = 3,
    ACTIONS(90), 1,
      sym__empty_params_decl,
    ACTIONS(92), 1,
      sym__o_brack,
    STATE(13), 1,
      sym_params_decl,
  [275] = 3,
    ACTIONS(94), 1,
      sym__colon,
    ACTIONS(96), 1,
      anon_sym_EQ,
    STATE(47), 1,
      sym__type_decl,
  [285] = 1,
    ACTIONS(98), 3,
      sym__c_brack,
      sym__comma,
      anon_sym_EQ,
  [291] = 2,
    ACTIONS(102), 1,
      sym__o_curly,
    ACTIONS(100), 2,
      sym__arrow_token,
      sym__empty_scope,
  [299] = 3,
    ACTIONS(104), 1,
      sym__c_brack,
    ACTIONS(106), 1,
      sym__comma,
    STATE(29), 1,
      aux_sym_params_decl_repeat1,
  [309] = 3,
    ACTIONS(68), 1,
      sym_ident,
    ACTIONS(109), 1,
      sym__c_brack,
    STATE(40), 1,
      sym_param_decl,
  [319] = 3,
    ACTIONS(111), 1,
      sym__c_brack,
    ACTIONS(113), 1,
      sym__comma,
    STATE(33), 1,
      aux_sym_params_decl_repeat1,
  [329] = 3,
    ACTIONS(92), 1,
      sym__o_brack,
    ACTIONS(115), 1,
      sym__empty_params_decl,
    STATE(14), 1,
      sym_params_decl,
  [339] = 3,
    ACTIONS(117), 1,
      sym__c_brack,
    ACTIONS(119), 1,
      sym__comma,
    STATE(29), 1,
      aux_sym_params_decl_repeat1,
  [349] = 3,
    ACTIONS(68), 1,
      sym_ident,
    ACTIONS(117), 1,
      sym__c_brack,
    STATE(40), 1,
      sym_param_decl,
  [359] = 2,
    ACTIONS(123), 1,
      sym__o_curly,
    ACTIONS(121), 2,
      sym__arrow_token,
      sym__empty_scope,
  [367] = 1,
    ACTIONS(125), 3,
      sym__c_curly,
      anon_sym_var,
      sym__return_token,
  [373] = 2,
    ACTIONS(129), 1,
      sym__o_curly,
    ACTIONS(127), 2,
      sym__arrow_token,
      sym__empty_scope,
  [381] = 3,
    ACTIONS(60), 1,
      sym__o_curly,
    ACTIONS(131), 1,
      sym__empty_scope,
    STATE(18), 1,
      sym_body,
  [391] = 3,
    ACTIONS(60), 1,
      sym__o_curly,
    ACTIONS(133), 1,
      sym__empty_scope,
    STATE(21), 1,
      sym_body,
  [401] = 1,
    ACTIONS(104), 2,
      sym__c_brack,
      sym__comma,
  [406] = 2,
    ACTIONS(135), 1,
      sym__empty_scope,
    ACTIONS(137), 1,
      sym__o_curly,
  [413] = 2,
    ACTIONS(94), 1,
      sym__colon,
    STATE(43), 1,
      sym__type_decl,
  [420] = 1,
    ACTIONS(139), 2,
      sym__c_brack,
      sym__comma,
  [425] = 2,
    ACTIONS(68), 1,
      sym_ident,
    STATE(40), 1,
      sym_param_decl,
  [432] = 1,
    ACTIONS(141), 1,
      sym_ident,
  [436] = 1,
    ACTIONS(143), 1,
      sym_ident,
  [440] = 1,
    ACTIONS(145), 1,
      anon_sym_EQ,
  [444] = 1,
    ACTIONS(147), 1,
      ts_builtin_sym_end,
  [448] = 1,
    ACTIONS(149), 1,
      anon_sym_func,
  [452] = 1,
    ACTIONS(111), 1,
      sym__c_brack,
  [456] = 1,
    ACTIONS(151), 1,
      sym_ident,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 16,
  [SMALL_STATE(4)] = 32,
  [SMALL_STATE(5)] = 50,
  [SMALL_STATE(6)] = 68,
  [SMALL_STATE(7)] = 86,
  [SMALL_STATE(8)] = 102,
  [SMALL_STATE(9)] = 113,
  [SMALL_STATE(10)] = 122,
  [SMALL_STATE(11)] = 131,
  [SMALL_STATE(12)] = 142,
  [SMALL_STATE(13)] = 152,
  [SMALL_STATE(14)] = 168,
  [SMALL_STATE(15)] = 184,
  [SMALL_STATE(16)] = 197,
  [SMALL_STATE(17)] = 204,
  [SMALL_STATE(18)] = 213,
  [SMALL_STATE(19)] = 220,
  [SMALL_STATE(20)] = 227,
  [SMALL_STATE(21)] = 234,
  [SMALL_STATE(22)] = 241,
  [SMALL_STATE(23)] = 248,
  [SMALL_STATE(24)] = 257,
  [SMALL_STATE(25)] = 265,
  [SMALL_STATE(26)] = 275,
  [SMALL_STATE(27)] = 285,
  [SMALL_STATE(28)] = 291,
  [SMALL_STATE(29)] = 299,
  [SMALL_STATE(30)] = 309,
  [SMALL_STATE(31)] = 319,
  [SMALL_STATE(32)] = 329,
  [SMALL_STATE(33)] = 339,
  [SMALL_STATE(34)] = 349,
  [SMALL_STATE(35)] = 359,
  [SMALL_STATE(36)] = 367,
  [SMALL_STATE(37)] = 373,
  [SMALL_STATE(38)] = 381,
  [SMALL_STATE(39)] = 391,
  [SMALL_STATE(40)] = 401,
  [SMALL_STATE(41)] = 406,
  [SMALL_STATE(42)] = 413,
  [SMALL_STATE(43)] = 420,
  [SMALL_STATE(44)] = 425,
  [SMALL_STATE(45)] = 432,
  [SMALL_STATE(46)] = 436,
  [SMALL_STATE(47)] = 440,
  [SMALL_STATE(48)] = 444,
  [SMALL_STATE(49)] = 448,
  [SMALL_STATE(50)] = 452,
  [SMALL_STATE(51)] = 456,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_body_repeat1, 2),
  [13] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_body_repeat1, 2), SHIFT_REPEAT(46),
  [16] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_body_repeat1, 2), SHIFT_REPEAT(4),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return, 1),
  [25] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_return, 1),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 1),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(45),
  [38] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(49),
  [41] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(46),
  [44] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [48] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_decl, 5, .production_id = 7),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_decl, 4, .production_id = 3),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [54] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type, 1),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [60] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_body, 3),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_decl, 6, .production_id = 9),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_decl, 4, .production_id = 1),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_decl, 5, .production_id = 6),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_decl, 5, .production_id = 4),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_body, 2),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_params_decl, 4),
  [88] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_params_decl, 4),
  [90] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [92] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [94] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [96] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__type_decl, 2, .production_id = 2),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_params_decl, 5),
  [102] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_params_decl, 5),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_params_decl_repeat1, 2),
  [106] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_params_decl_repeat1, 2), SHIFT_REPEAT(44),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_params_decl, 3),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_params_decl, 3),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return, 2, .production_id = 8),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_params_decl, 2),
  [129] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_params_decl, 2),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [133] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__func_type_decl, 2),
  [137] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__func_type_decl, 2),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_param_decl, 2, .production_id = 5),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [147] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
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
