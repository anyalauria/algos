#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void merge(int *arr, int a, int b, int c) {
   int *arr1, *arr2;
   int m, n, i, j, k, flag;
   m = b-a+1;
   n = c-b;
// create two subsidiary arrays
   arr1 = (int *) malloc(m * sizeof(int));
   arr2 = (int *) malloc(n * sizeof(int));
// copy the two array subsets to these two arrays
   for(i=a, k=0; i<=b; i++) arr1[k++]=arr[i];
   for(i=b+1, k=0; i<=c; i++) arr2[k++]=arr[i];
// now, merge these two subsidiary arrays, copying them back to the
// original array that we get from the caller
   i = 0; j = 0; k = a; flag = 0; 
// iterate over each array, moving the smaller element
// to the resultant array each time
   while(flag == 0) {
      if(arr1[i] <= arr2[j]) {
         arr[k] = arr1[i];
         k++; i++;
         if(i == m) flag = 1;
      } else {
         arr[k] = arr2[j];
         k++; j++;
         if(j == n) flag = 2;
      }
   }
// depending on which array finished, move the other
// array to the resultant array
   if(flag == 1) {
      while(j < n) {
         arr[k] = arr2[j]; j++; k++;
      }
   } else {
      while(i < m) {
         arr[k] = arr1[i]; i++; k++;
      }
   }
   free(arr1); free(arr2);
}
void mergeSort(int *arr, int n1, int n2) {
   int midPt;
// trivial cases, size 1 and 2 subarrays
   if(n1 == n2) return;
   if(n2-n1 == 1) {
      if(arr[n1] > arr[n2]) {
         int temp = arr[n1];
         arr[n1] = arr[n2];
         arr[n2] = temp;
         return;
      }
   }
// when numElements is 3 or more
// divide the range into two ranges, mergeSort
// the two sub-arrays (recursively), and merge
   midPt = n1 + (n2-n1)/2;
   mergeSort(arr, n1, midPt);
   mergeSort(arr, midPt+1, n2);
   merge(arr, n1, midPt, n2);
}

int main(int argc, char **argv) {
   int m;
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
   mergeSort(arr1,0,m-1);
// check and print the final array
   printf("*******************************\n");
   for(int i=0;i<m-1;i++) {
      if(arr1[i]>arr1[i+1])printf("yeh kya hua, kyon hua, kaise hua\n");
      printf("%d \n",arr1[i]);
   }
   printf("%d\n",arr1[m-1]);
   exit(0);
}
