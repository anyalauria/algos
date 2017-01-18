#include <stdio.h>
#include <stdlib.h>

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
   int val1, val2, i, flag;
   int cpVal1, cpVal2, carryOut;
   int arr3[33]={0};
   if(argc == 3) {
      val1 = atoi(argv[1]);
      val2 = atoi(argv[2]);
   } else {
      printf("Please give two integer arguments for adding\n");
      exit(1);
   }
// copy the initial numbers to other variables
   cpVal1 = val1; cpVal2 = val2;
// Add the two numbers bit-wise
   for(i = 0, carryOut = 0, flag = 1; flag == 1; i++) {
      int v1 = cpVal1 & 1, v2 = cpVal2 & 1;
      int sum = v1 + v2 + carryOut;
      switch (sum) {
        case 0: arr3[i] = 0; carryOut = 0; break;
        case 1: arr3[i] = 1; carryOut = 0; break;
        case 2: arr3[i] = 0; carryOut = 1; break; 
        case 3: arr3[i] = 1; carryOut = 1; break;
      }
      cpVal1 = cpVal1 >> 1;
      cpVal2 = cpVal2 >> 1;
      flag = cpVal1 > 0 || cpVal2 > 0;
   }
   if(carryOut == 1)
      arr3[i] = carryOut;
   else 
      i--;
   for(int k = i; k>=0; k--) {
      printf("%d",arr3[k]);
   }
   printf("\n");
   printf("%d %d\n", val1+val2, arr2int(arr3, i));
   exit(0);
}
