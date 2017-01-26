#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void printIt(int *arr, int n1, int n2) {
   for(int i = n1; i<=n2;i++) printf("%d ",arr[i]);
   printf("\n");
}
int partIt(int *arr, int n1, int n2) {
   int i, j, pivot, temp;
   pivot = arr[n2];
   i = n1;
   printf("pivot=%d\n", pivot);
   for (j=n1;j<n2;j++) {
      if(arr[j] < pivot) {
         temp = arr[i];
         arr[i] = arr[j];
         arr[j] = temp;
         i += 1;
      }
      printf("i=%d, j=%d\n", i, j);
      printIt(arr, n1, n2);
   }
   temp = arr[n2];
   arr[n2] = arr[i];
   arr[i] = temp;
   return i;
}
void quikSort(int *arr, int n1, int n2) {
   int midPt;
   if(n1 < n2) {
      midPt = partIt(arr, n1, n2); 
      quikSort(arr, n1, midPt-1);
      quikSort(arr, midPt+1, n2);
   }
}

int main(int argc, char **argv) {
   int m, numErr=0;
   int *arr1;
// get value of m
   if (argc == 2) {
      m = atoi(argv[1]);
   } else {
      printf("Error - Give the value for array size - m \n");
      exit(1);
   }
// create the array
   arr1 = (int *) malloc(m * sizeof(int));
// fill the array
   for(int i=0; i<m; i++) {
      arr1[i] = rand()/1000;
   }
   quikSort(arr1,0,m-1);
// check and print the final array
   printf("*******************************\n");
   for(int i=0;i<m-1;i++) {
      if(arr1[i]>arr1[i+1]) {
         numErr++;
      }  
   }
   exit(numErr);
}
