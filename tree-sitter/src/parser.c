#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 61
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 45
#define ALIAS_COUNT 0
#define TOKEN_COUNT 26
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
  sym__o_paren = 8,
  sym__c_paren = 9,
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
  anon_sym_DASH = 21,
  anon_sym_STAR = 22,
  anon_sym_SLASH = 23,
  anon_sym_PLUS = 24,
  sym_int_literal = 25,
  sym_program = 26,
  sym_func_decl = 27,
  sym__func_type_decl = 28,
  sym_params_decl = 29,
  sym_param_decl = 30,
  sym_body = 31,
  sym_var_decl = 32,
  sym_return = 33,
  sym_type = 34,
  sym__type_decl = 35,
  sym__statement = 36,
  sym__expression = 37,
  sym__expr_with_paren = 38,
  sym_unary_expr = 39,
  sym_binary_expr = 40,
  sym__literal_val = 41,
  aux_sym_program_repeat1 = 42,
  aux_sym_params_decl_repeat1 = 43,
  aux_sym_body_repeat1 = 44,
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
  [sym__o_paren] = "_o_paren",
  [sym__c_paren] = "_c_paren",
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
  [anon_sym_DASH] = "-",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_PLUS] = "+",
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
  [sym__expr_with_paren] = "_expr_with_paren",
  [sym_unary_expr] = "unary_expr",
  [sym_binary_expr] = "binary_expr",
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
  [sym__o_paren] = sym__o_paren,
  [sym__c_paren] = sym__c_paren,
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
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_PLUS] = anon_sym_PLUS,
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
  [sym__expr_with_paren] = sym__expr_with_paren,
  [sym_unary_expr] = sym_unary_expr,
  [sym_binary_expr] = sym_binary_expr,
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
  [sym__o_paren] = {
    .visible = false,
    .named = true,
  },
  [sym__c_paren] = {
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
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
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
  [sym__expr_with_paren] = {
    .visible = false,
    .named = true,
  },
  [sym_unary_expr] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_expr] = {
    .visible = true,
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
      if (eof) ADVANCE(28);
      if (lookahead == '(') ADVANCE(37);
      if (lookahead == ')') ADVANCE(38);
      if (lookahead == '*') ADVANCE(62);
      if (lookahead == '+') ADVANCE(64);
      if (lookahead == ',') ADVANCE(40);
      if (lookahead == '-') ADVANCE(61);
      if (lookahead == '/') ADVANCE(63);
      if (lookahead == ':') ADVANCE(39);
      if (lookahead == '=') ADVANCE(43);
      if (lookahead == 'V') ADVANCE(19);
      if (lookahead == 'f') ADVANCE(6);
      if (lookahead == 'i') ADVANCE(7);
      if (lookahead == 'p') ADVANCE(24);
      if (lookahead == 'r') ADVANCE(15);
      if (lookahead == 'v') ADVANCE(11);
      if (lookahead == '{') ADVANCE(34);
      if (lookahead == '}') ADVANCE(35);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(65);
      END_STATE();
    case 1:
      if (lookahead == '(') ADVANCE(36);
      if (lookahead == ')') ADVANCE(38);
      if (lookahead == '*') ADVANCE(62);
      if (lookahead == '+') ADVANCE(64);
      if (lookahead == '-') ADVANCE(60);
      if (lookahead == '/') ADVANCE(63);
      if (lookahead == 'r') ADVANCE(47);
      if (lookahead == 'v') ADVANCE(46);
      if (lookahead == '}') ADVANCE(35);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(65);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 2:
      if (lookahead == '(') ADVANCE(36);
      if (lookahead == ')') ADVANCE(38);
      if (lookahead == ',') ADVANCE(40);
      if (lookahead == '-') ADVANCE(60);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(65);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 3:
      if (lookahead == '-') ADVANCE(10);
      if (lookahead == '{') ADVANCE(34);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      END_STATE();
    case 4:
      if (lookahead == '2') ADVANCE(57);
      END_STATE();
    case 5:
      if (lookahead == '2') ADVANCE(55);
      END_STATE();
    case 6:
      if (lookahead == '3') ADVANCE(4);
      if (lookahead == '6') ADVANCE(8);
      if (lookahead == 'u') ADVANCE(17);
      END_STATE();
    case 7:
      if (lookahead == '3') ADVANCE(5);
      if (lookahead == '6') ADVANCE(9);
      END_STATE();
    case 8:
      if (lookahead == '4') ADVANCE(58);
      END_STATE();
    case 9:
      if (lookahead == '4') ADVANCE(56);
      END_STATE();
    case 10:
      if (lookahead == '>') ADVANCE(30);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(20);
      END_STATE();
    case 12:
      if (lookahead == 'b') ADVANCE(32);
      END_STATE();
    case 13:
      if (lookahead == 'c') ADVANCE(29);
      END_STATE();
    case 14:
      if (lookahead == 'd') ADVANCE(59);
      END_STATE();
    case 15:
      if (lookahead == 'e') ADVANCE(22);
      END_STATE();
    case 16:
      if (lookahead == 'i') ADVANCE(14);
      END_STATE();
    case 17:
      if (lookahead == 'n') ADVANCE(13);
      END_STATE();
    case 18:
      if (lookahead == 'n') ADVANCE(44);
      END_STATE();
    case 19:
      if (lookahead == 'o') ADVANCE(16);
      END_STATE();
    case 20:
      if (lookahead == 'r') ADVANCE(41);
      END_STATE();
    case 21:
      if (lookahead == 'r') ADVANCE(18);
      END_STATE();
    case 22:
      if (lookahead == 't') ADVANCE(25);
      END_STATE();
    case 23:
      if (lookahead == 'u') ADVANCE(17);
      END_STATE();
    case 24:
      if (lookahead == 'u') ADVANCE(12);
      END_STATE();
    case 25:
      if (lookahead == 'u') ADVANCE(21);
      END_STATE();
    case 26:
      if (lookahead == '}') ADVANCE(31);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(26);
      END_STATE();
    case 27:
      if (eof) ADVANCE(28);
      if (lookahead == ')') ADVANCE(38);
      if (lookahead == '*') ADVANCE(62);
      if (lookahead == '+') ADVANCE(64);
      if (lookahead == '-') ADVANCE(60);
      if (lookahead == '/') ADVANCE(63);
      if (lookahead == 'f') ADVANCE(23);
      if (lookahead == 'p') ADVANCE(24);
      if (lookahead == 'r') ADVANCE(15);
      if (lookahead == 'v') ADVANCE(11);
      if (lookahead == '}') ADVANCE(35);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(27)
      END_STATE();
    case 28:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_func);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym__arrow_token);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym__empty_scope);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_pub);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym__empty_params_decl);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym__o_curly);
      if (lookahead == '}') ADVANCE(31);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(26);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym__c_curly);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym__o_paren);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym__o_paren);
      if (lookahead == ')') ADVANCE(33);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym__c_paren);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym__colon);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym__comma);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_var);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_var);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(54);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym__return_token);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym__return_token);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(54);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'a') ADVANCE(49);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(54);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'e') ADVANCE(51);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(54);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'n') ADVANCE(45);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(54);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'r') ADVANCE(42);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(54);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'r') ADVANCE(48);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(54);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 't') ADVANCE(52);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(54);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == 'u') ADVANCE(50);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(54);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(54);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_ident);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(54);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_i32);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_i64);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_f32);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_f64);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_Void);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '>') ADVANCE(30);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_int_literal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(65);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 1},
  [3] = {.lex_state = 27},
  [4] = {.lex_state = 27},
  [5] = {.lex_state = 27},
  [6] = {.lex_state = 27},
  [7] = {.lex_state = 27},
  [8] = {.lex_state = 27},
  [9] = {.lex_state = 2},
  [10] = {.lex_state = 2},
  [11] = {.lex_state = 2},
  [12] = {.lex_state = 2},
  [13] = {.lex_state = 2},
  [14] = {.lex_state = 2},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 27},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 3},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 3},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 2},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 2},
  [37] = {.lex_state = 3},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 2},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 3},
  [44] = {.lex_state = 3},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 3},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 2},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 2},
  [56] = {.lex_state = 2},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 2},
  [60] = {.lex_state = 0},
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
    [sym__o_paren] = ACTIONS(1),
    [sym__c_paren] = ACTIONS(1),
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
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [sym_int_literal] = ACTIONS(1),
  },
  [1] = {
    [sym_program] = STATE(58),
    [sym_func_decl] = STATE(17),
    [sym_var_decl] = STATE(17),
    [aux_sym_program_repeat1] = STATE(17),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_func] = ACTIONS(5),
    [sym_pub] = ACTIONS(7),
    [anon_sym_var] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 7,
    ACTIONS(11), 1,
      sym__c_curly,
    ACTIONS(13), 1,
      sym__o_paren,
    ACTIONS(17), 1,
      sym_ident,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(21), 1,
      sym_int_literal,
    ACTIONS(15), 2,
      anon_sym_var,
      sym__return_token,
    STATE(16), 5,
      sym__expression,
      sym__expr_with_paren,
      sym_unary_expr,
      sym_binary_expr,
      sym__literal_val,
  [27] = 1,
    ACTIONS(23), 11,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      sym__c_curly,
      sym__c_paren,
      anon_sym_var,
      sym__return_token,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
  [41] = 2,
    ACTIONS(25), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(23), 9,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      sym__c_curly,
      sym__c_paren,
      anon_sym_var,
      sym__return_token,
      anon_sym_DASH,
      anon_sym_PLUS,
  [57] = 1,
    ACTIONS(27), 11,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      sym__c_curly,
      sym__c_paren,
      anon_sym_var,
      sym__return_token,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
  [71] = 1,
    ACTIONS(29), 11,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      sym__c_curly,
      sym__c_paren,
      anon_sym_var,
      sym__return_token,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PLUS,
  [85] = 3,
    ACTIONS(25), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(33), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(31), 6,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      sym__c_curly,
      anon_sym_var,
      sym__return_token,
  [102] = 3,
    ACTIONS(25), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(33), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(35), 6,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      sym__c_curly,
      anon_sym_var,
      sym__return_token,
  [119] = 4,
    ACTIONS(13), 1,
      sym__o_paren,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(37), 2,
      sym_ident,
      sym_int_literal,
    STATE(4), 5,
      sym__expression,
      sym__expr_with_paren,
      sym_unary_expr,
      sym_binary_expr,
      sym__literal_val,
  [137] = 4,
    ACTIONS(13), 1,
      sym__o_paren,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(39), 2,
      sym_ident,
      sym_int_literal,
    STATE(6), 5,
      sym__expression,
      sym__expr_with_paren,
      sym_unary_expr,
      sym_binary_expr,
      sym__literal_val,
  [155] = 4,
    ACTIONS(13), 1,
      sym__o_paren,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(41), 2,
      sym_ident,
      sym_int_literal,
    STATE(7), 5,
      sym__expression,
      sym__expr_with_paren,
      sym_unary_expr,
      sym_binary_expr,
      sym__literal_val,
  [173] = 4,
    ACTIONS(13), 1,
      sym__o_paren,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(43), 2,
      sym_ident,
      sym_int_literal,
    STATE(3), 5,
      sym__expression,
      sym__expr_with_paren,
      sym_unary_expr,
      sym_binary_expr,
      sym__literal_val,
  [191] = 4,
    ACTIONS(13), 1,
      sym__o_paren,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(45), 2,
      sym_ident,
      sym_int_literal,
    STATE(8), 5,
      sym__expression,
      sym__expr_with_paren,
      sym_unary_expr,
      sym_binary_expr,
      sym__literal_val,
  [209] = 4,
    ACTIONS(13), 1,
      sym__o_paren,
    ACTIONS(19), 1,
      anon_sym_DASH,
    ACTIONS(47), 2,
      sym_ident,
      sym_int_literal,
    STATE(24), 5,
      sym__expression,
      sym__expr_with_paren,
      sym_unary_expr,
      sym_binary_expr,
      sym__literal_val,
  [227] = 4,
    ACTIONS(49), 1,
      sym__c_curly,
    ACTIONS(51), 1,
      anon_sym_var,
    ACTIONS(54), 1,
      sym__return_token,
    STATE(15), 4,
      sym_var_decl,
      sym_return,
      sym__statement,
      aux_sym_body_repeat1,
  [243] = 3,
    ACTIONS(25), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(33), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(57), 3,
      sym__c_curly,
      anon_sym_var,
      sym__return_token,
  [257] = 5,
    ACTIONS(5), 1,
      anon_sym_func,
    ACTIONS(7), 1,
      sym_pub,
    ACTIONS(9), 1,
      anon_sym_var,
    ACTIONS(59), 1,
      ts_builtin_sym_end,
    STATE(20), 3,
      sym_func_decl,
      sym_var_decl,
      aux_sym_program_repeat1,
  [275] = 4,
    ACTIONS(9), 1,
      anon_sym_var,
    ACTIONS(61), 1,
      sym__c_curly,
    ACTIONS(63), 1,
      sym__return_token,
    STATE(19), 4,
      sym_var_decl,
      sym_return,
      sym__statement,
      aux_sym_body_repeat1,
  [291] = 4,
    ACTIONS(9), 1,
      anon_sym_var,
    ACTIONS(63), 1,
      sym__return_token,
    ACTIONS(65), 1,
      sym__c_curly,
    STATE(15), 4,
      sym_var_decl,
      sym_return,
      sym__statement,
      aux_sym_body_repeat1,
  [307] = 5,
    ACTIONS(67), 1,
      ts_builtin_sym_end,
    ACTIONS(69), 1,
      anon_sym_func,
    ACTIONS(72), 1,
      sym_pub,
    ACTIONS(75), 1,
      anon_sym_var,
    STATE(20), 3,
      sym_func_decl,
      sym_var_decl,
      aux_sym_program_repeat1,
  [325] = 2,
    STATE(41), 1,
      sym_type,
    ACTIONS(78), 5,
      anon_sym_i32,
      anon_sym_i64,
      anon_sym_f32,
      anon_sym_f64,
      anon_sym_Void,
  [336] = 2,
    STATE(52), 1,
      sym_type,
    ACTIONS(78), 5,
      anon_sym_i32,
      anon_sym_i64,
      anon_sym_f32,
      anon_sym_f64,
      anon_sym_Void,
  [347] = 5,
    ACTIONS(80), 1,
      sym__arrow_token,
    ACTIONS(82), 1,
      sym__empty_scope,
    ACTIONS(84), 1,
      sym__o_curly,
    STATE(30), 1,
      sym_body,
    STATE(46), 1,
      sym__func_type_decl,
  [363] = 3,
    ACTIONS(86), 1,
      sym__c_paren,
    ACTIONS(25), 2,
      anon_sym_STAR,
      anon_sym_SLASH,
    ACTIONS(33), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
  [375] = 5,
    ACTIONS(80), 1,
      sym__arrow_token,
    ACTIONS(84), 1,
      sym__o_curly,
    ACTIONS(88), 1,
      sym__empty_scope,
    STATE(33), 1,
      sym_body,
    STATE(42), 1,
      sym__func_type_decl,
  [391] = 2,
    ACTIONS(92), 1,
      sym__o_curly,
    ACTIONS(90), 4,
      sym__empty_scope,
      sym__c_paren,
      sym__comma,
      anon_sym_EQ,
  [401] = 1,
    ACTIONS(94), 4,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      anon_sym_var,
  [408] = 1,
    ACTIONS(96), 4,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      anon_sym_var,
  [415] = 1,
    ACTIONS(98), 4,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      anon_sym_var,
  [422] = 1,
    ACTIONS(100), 4,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      anon_sym_var,
  [429] = 4,
    ACTIONS(102), 1,
      sym__c_paren,
    ACTIONS(104), 1,
      sym__comma,
    ACTIONS(106), 1,
      sym_ident,
    STATE(34), 1,
      sym_param_decl,
  [442] = 1,
    ACTIONS(108), 4,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      anon_sym_var,
  [449] = 1,
    ACTIONS(110), 4,
      ts_builtin_sym_end,
      anon_sym_func,
      sym_pub,
      anon_sym_var,
  [456] = 3,
    ACTIONS(112), 1,
      sym__c_paren,
    ACTIONS(114), 1,
      sym__comma,
    STATE(40), 1,
      aux_sym_params_decl_repeat1,
  [466] = 3,
    ACTIONS(116), 1,
      sym__colon,
    ACTIONS(118), 1,
      anon_sym_EQ,
    STATE(54), 1,
      sym__type_decl,
  [476] = 3,
    ACTIONS(106), 1,
      sym_ident,
    ACTIONS(120), 1,
      sym__c_paren,
    STATE(49), 1,
      sym_param_decl,
  [486] = 2,
    ACTIONS(124), 1,
      sym__o_curly,
    ACTIONS(122), 2,
      sym__arrow_token,
      sym__empty_scope,
  [494] = 3,
    ACTIONS(126), 1,
      sym__empty_params_decl,
    ACTIONS(128), 1,
      sym__o_paren,
    STATE(25), 1,
      sym_params_decl,
  [504] = 3,
    ACTIONS(106), 1,
      sym_ident,
    ACTIONS(130), 1,
      sym__c_paren,
    STATE(49), 1,
      sym_param_decl,
  [514] = 3,
    ACTIONS(130), 1,
      sym__c_paren,
    ACTIONS(132), 1,
      sym__comma,
    STATE(47), 1,
      aux_sym_params_decl_repeat1,
  [524] = 1,
    ACTIONS(134), 3,
      sym__c_paren,
      sym__comma,
      anon_sym_EQ,
  [530] = 3,
    ACTIONS(84), 1,
      sym__o_curly,
    ACTIONS(136), 1,
      sym__empty_scope,
    STATE(32), 1,
      sym_body,
  [540] = 2,
    ACTIONS(140), 1,
      sym__o_curly,
    ACTIONS(138), 2,
      sym__arrow_token,
      sym__empty_scope,
  [548] = 2,
    ACTIONS(144), 1,
      sym__o_curly,
    ACTIONS(142), 2,
      sym__arrow_token,
      sym__empty_scope,
  [556] = 3,
    ACTIONS(128), 1,
      sym__o_paren,
    ACTIONS(146), 1,
      sym__empty_params_decl,
    STATE(23), 1,
      sym_params_decl,
  [566] = 3,
    ACTIONS(84), 1,
      sym__o_curly,
    ACTIONS(148), 1,
      sym__empty_scope,
    STATE(28), 1,
      sym_body,
  [576] = 3,
    ACTIONS(150), 1,
      sym__c_paren,
    ACTIONS(152), 1,
      sym__comma,
    STATE(47), 1,
      aux_sym_params_decl_repeat1,
  [586] = 2,
    ACTIONS(157), 1,
      sym__o_curly,
    ACTIONS(155), 2,
      sym__arrow_token,
      sym__empty_scope,
  [594] = 1,
    ACTIONS(150), 2,
      sym__c_paren,
      sym__comma,
  [599] = 1,
    ACTIONS(159), 2,
      sym__c_paren,
      sym__comma,
  [604] = 2,
    ACTIONS(116), 1,
      sym__colon,
    STATE(50), 1,
      sym__type_decl,
  [611] = 2,
    ACTIONS(161), 1,
      sym__empty_scope,
    ACTIONS(163), 1,
      sym__o_curly,
  [618] = 2,
    ACTIONS(106), 1,
      sym_ident,
    STATE(49), 1,
      sym_param_decl,
  [625] = 1,
    ACTIONS(165), 1,
      anon_sym_EQ,
  [629] = 1,
    ACTIONS(167), 1,
      sym_ident,
  [633] = 1,
    ACTIONS(169), 1,
      sym_ident,
  [637] = 1,
    ACTIONS(112), 1,
      sym__c_paren,
  [641] = 1,
    ACTIONS(171), 1,
      ts_builtin_sym_end,
  [645] = 1,
    ACTIONS(173), 1,
      sym_ident,
  [649] = 1,
    ACTIONS(175), 1,
      anon_sym_func,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 27,
  [SMALL_STATE(4)] = 41,
  [SMALL_STATE(5)] = 57,
  [SMALL_STATE(6)] = 71,
  [SMALL_STATE(7)] = 85,
  [SMALL_STATE(8)] = 102,
  [SMALL_STATE(9)] = 119,
  [SMALL_STATE(10)] = 137,
  [SMALL_STATE(11)] = 155,
  [SMALL_STATE(12)] = 173,
  [SMALL_STATE(13)] = 191,
  [SMALL_STATE(14)] = 209,
  [SMALL_STATE(15)] = 227,
  [SMALL_STATE(16)] = 243,
  [SMALL_STATE(17)] = 257,
  [SMALL_STATE(18)] = 275,
  [SMALL_STATE(19)] = 291,
  [SMALL_STATE(20)] = 307,
  [SMALL_STATE(21)] = 325,
  [SMALL_STATE(22)] = 336,
  [SMALL_STATE(23)] = 347,
  [SMALL_STATE(24)] = 363,
  [SMALL_STATE(25)] = 375,
  [SMALL_STATE(26)] = 391,
  [SMALL_STATE(27)] = 401,
  [SMALL_STATE(28)] = 408,
  [SMALL_STATE(29)] = 415,
  [SMALL_STATE(30)] = 422,
  [SMALL_STATE(31)] = 429,
  [SMALL_STATE(32)] = 442,
  [SMALL_STATE(33)] = 449,
  [SMALL_STATE(34)] = 456,
  [SMALL_STATE(35)] = 466,
  [SMALL_STATE(36)] = 476,
  [SMALL_STATE(37)] = 486,
  [SMALL_STATE(38)] = 494,
  [SMALL_STATE(39)] = 504,
  [SMALL_STATE(40)] = 514,
  [SMALL_STATE(41)] = 524,
  [SMALL_STATE(42)] = 530,
  [SMALL_STATE(43)] = 540,
  [SMALL_STATE(44)] = 548,
  [SMALL_STATE(45)] = 556,
  [SMALL_STATE(46)] = 566,
  [SMALL_STATE(47)] = 576,
  [SMALL_STATE(48)] = 586,
  [SMALL_STATE(49)] = 594,
  [SMALL_STATE(50)] = 599,
  [SMALL_STATE(51)] = 604,
  [SMALL_STATE(52)] = 611,
  [SMALL_STATE(53)] = 618,
  [SMALL_STATE(54)] = 625,
  [SMALL_STATE(55)] = 629,
  [SMALL_STATE(56)] = 633,
  [SMALL_STATE(57)] = 637,
  [SMALL_STATE(58)] = 641,
  [SMALL_STATE(59)] = 645,
  [SMALL_STATE(60)] = 649,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return, 1),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [15] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_return, 1),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expr, 3),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expr_with_paren, 3),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unary_expr, 2),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_decl, 4, .production_id = 3),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_decl, 5, .production_id = 7),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_body_repeat1, 2),
  [51] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_body_repeat1, 2), SHIFT_REPEAT(59),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_body_repeat1, 2), SHIFT_REPEAT(2),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return, 2, .production_id = 8),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 1),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2),
  [69] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(55),
  [72] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(60),
  [75] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(59),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [84] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [86] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [88] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [92] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type, 1),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_body, 2),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_decl, 5, .production_id = 4),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_body, 3),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_decl, 4, .production_id = 1),
  [102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [104] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_decl, 6, .production_id = 9),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_decl, 5, .production_id = 6),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_params_decl, 3),
  [124] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_params_decl, 3),
  [126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [128] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__type_decl, 2, .production_id = 2),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_params_decl, 2),
  [140] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_params_decl, 2),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_params_decl, 4),
  [144] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_params_decl, 4),
  [146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_params_decl_repeat1, 2),
  [152] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_params_decl_repeat1, 2), SHIFT_REPEAT(53),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_params_decl, 5),
  [157] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_params_decl, 5),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_param_decl, 2, .production_id = 5),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__func_type_decl, 2),
  [163] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__func_type_decl, 2),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [171] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
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
