#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
   int multVal = 0;
   int toAdd, val1, val2, savedVal2;
   if(argc != 3) {
      printf("Please give two arguments\n");
      exit(1);
   } else {
      val1 = atoi(argv[1]);
      val2 = atoi(argv[2]);
   }
   toAdd = val1;
   savedVal2 = val2;
   while(val2 != 0) {
      if(val2 & 1 == 1) {
         multVal = multVal + toAdd;
      }
      val2 = val2 >> 1;
      toAdd = toAdd << 1;   
   } 
   printf("Val 1 = %d, Val2 = %d, MultOur = %d, Actual Mult = %d\n",
         val1, savedVal2, multVal, val1*savedVal2);
   exit(0);
}
