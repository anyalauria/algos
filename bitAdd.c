#include <stdio.h>
#include <stdlib.h>
#ifndef max
    #define max(a,b) ((a) > (b) ? (a) : (b))
#endif

int arr2int(int *bitArr, int len) {
   int sum = 0;
   int posVal = 1;
   for (int i = 0; i <= len; i++) {
      if (bitArr[i] == 1) sum += posVal;
      posVal = posVal << 1;
   }
   return sum;
}
int main(int argc, char ** argv) {
   int val1, val2, i, j, ij;
   int cpVal1, cpVal2, carryOut;
   int arr1[32]={0}, arr2[32]={0};
   int arr3[33]={0};
   if(argc == 3) {
      val1 = atoi(argv[1]);
      val2 = atoi(argv[2]);
   } else {
      printf("Please give two integer arguments for adding\n");
      exit(1);
   }
// since the conversion is destructive (right shifts),
// we do the conversion on a copy (each) of the two
// initial numbers
   cpVal1 = val1; cpVal2 = val2;
// convert the first number to an array of bits
   i = 0;
   while(cpVal1) {
      arr1[i] = cpVal1&1;
      i++;
      cpVal1 = cpVal1 >> 1;
   }
// convert the second number to an array of bits
   j = 0;
   while(cpVal2) {
      arr2[j] = cpVal2&1;
      j++;
      cpVal2 = cpVal2 >> 1;
   }
// print the two numbers and their bit representation
   for(int k = i-1; k >= 0; k--) {
      printf("%d",arr1[k]);
   }
   printf("\n");
   for(int k = j-1; k >=0; k--) {
      printf("%d",arr2[k]);
   }
   printf("\n");
// Add the two numbers bit-wise
   for(ij = 0, carryOut = 0; ij < max(i,j); ij++) {
      int sum = arr1[ij] + arr2[ij] + carryOut;
      switch (sum) {
        case 0: arr3[ij] = 0; carryOut = 0; break;
        case 1: arr3[ij] = 1; carryOut = 0; break;
        case 2: arr3[ij] = 0; carryOut = 1; break; 
        case 3: arr3[ij] = 1; carryOut = 1; break;
      }
   }
   if(carryOut == 1)
      arr3[ij] = carryOut;
   else 
      ij--;
   for(int k = ij; k>=0; k--) {
      printf("%d",arr3[k]);
   }
   printf("\n");
   printf("%d %d\n", val1+val2, arr2int(arr3, ij));
   exit(0);
}
