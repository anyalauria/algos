#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void bubb(int *A, int N) {
   for (int i = N-1; i >= 0; i--) {
      for (int j = 0; j <= i-1; j++) {
         if(A[j] > A[j+1]) {
            int temp = A[j];
            A[j] = A[j+1];
            A[j+1] = temp;
         }
      }
   }
}

int main(int argc, char **argv) {
   int m, n, tot;
   int i,j,k,flag;
   int *arr1, *arr2, *arr3;
// get values of m and n
   if (argc == 3) {
      m = atoi(argv[1]);
      n = atoi(argv[2]);
      tot = m + n;
   } else {
      printf("Error - Give values for array sizes - m and n\n");
      exit(1);
   }
// create the three arrays
   arr1 = (int *) malloc(m * sizeof(int));
   arr2 = (int *) malloc(n * sizeof(int));
   arr3 = (int *) malloc(tot * sizeof(int));
// fill two of those arrays, sort them using an auxiliary sorting algo
   for(i=0; i<m; i++) {
      arr1[i] = rand()/1000;
   }
   bubb(arr1, m);
   printf("*******************************\n");
   for(i=0;i<(m-1);i++) {
      if(arr1[i]>arr1[i+1])printf("yeh kya hua, kyon hua, kaise hua\n");
      printf("%d \n",arr1[i]);
   }
   printf("%d\n",arr1[m-1]);
   for(i=0; i<n; i++) {
      arr2[i] = rand()/1000;
   }
   bubb(arr2, n);
   printf("*******************************\n");
   for(i=0;i<(n-1);i++) {
      if(arr2[i]>arr2[i+1])printf("yeh kya hua, kyon hua, kaise hua\n");
      printf("%d \n",arr2[i]);
   }
   printf("%d\n",arr2[n-1]);
// now merge the two sorted arrays
   i = 0; j = 0; k = 0; flag = 0;
   while(flag == 0) {
      if(arr1[i] <= arr2[j]) {
         arr3[k] = arr1[i];
         k++; i++;
         if(i == m) flag = 1;
      } else {
         arr3[k] = arr2[j];
         k++; j++;
         if(j == n) flag = 2;
      }
   }
   if(flag == 1) {
      while(j < n) {
         arr3[k] = arr2[j]; j++; k++;
      }
   } else {
      while(i < m) {
         arr3[k] = arr1[i]; j++; k++;
      }
   }
// check and print the third array
   printf("*******************************\n");
   for(i=0;i<(tot-1);i++) {
      if(arr3[i]>arr3[i+1])printf("yeh kya hua, kyon hua, kaise hua\n");
      printf("%d \n",arr3[i]);
   }
   printf("%d\n",arr3[tot-1]);
   exit(0);
}
