#include <stdio.h>

int main(int argc, char **argv) {
   printf("number of argumnets = %d\n", argc);
   for(int i = 0; i < argc; i++) {
      printf("Argument number %d = %s\n", i, argv[i]);
   }
   return 0;
}
