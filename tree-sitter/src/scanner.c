#include <tree_sitter/parser.h>
#include <stdio.h>

enum TokenType {
    EIGHT
};

void * tree_sitter_wasm_lang_external_scanner_create() { return NULL; }

void tree_sitter_wasm_lang_external_scanner_destroy(void *payload) {}

unsigned tree_sitter_wasm_lang_external_scanner_serialize(void *payload, char *buffer) { return 0; }

void tree_sitter_wasm_lang_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {}

bool tree_sitter_wasm_lang_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
  printf("char: %c\n", lexer->lookahead);
  lexer->result_symbol = 0;
  lexer->advance(lexer, 0);
  return true;
}
