#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/token.h"
#include "../include/tokenizer.h"
#include "../include/util.h"

int main(int argc, char** argv) {
   if (strcmp(argv[1], "--help") == 0) {
      printf("Usage: %s compile <file>.umb\n", argv[0]);
      return 0;
   }

   char* code = read_file(argv[1]);

   TokenList tokens = {0};
   generate_tokens(code, &tokens);

   for (int i = 0; i < tokens.ptr; i++) {
      Token* token = token_list_get(&tokens, i);
      printf("<type: %s, value: '%s', line: %d>\n", get_token_type_name(token->type), token->value,
             token->line);
   }

   free(code);

   return 0;
}
