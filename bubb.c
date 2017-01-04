#include <stdio.h>

int main() {
   int A[14] = {8,67,100,13,51,52,3,71,29,38,92,85,21,4}, N=14;
   for (int i = N-1; i >= 0; i--) { 
      for (int j = 0; j <= i-1; j++) {
         if(A[j] > A[j+1]) {
            int temp = A[j];
            A[j] = A[j+1];
            A[j+1] = temp;
         }
      }
   }
   for (int i = 0; i < 14; i++) {
      printf("%d ", A[i]);
   }
   printf("\n");
   
   return 0;
}
