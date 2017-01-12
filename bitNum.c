#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
   int val, i=0;
   int arr[32];
   if(argc == 2) {
      val = atoi(argv[1]);
   } else {
      printf("Please give one integer argument\n");
      exit(1);
   }
   while(val) {
      arr[i] = val&1;
      i++;
      val = val >> 1;
   }
   for(int j=i-1; j >= 0; j--){
      printf("%d",arr[j]);
   }
   printf("\n");
   exit(0);
}
