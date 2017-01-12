#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
   int n;
   long long int *arr;
   if (argc == 2)
      n = atoi(argv[1]); 
   arr = (long long int *) malloc((n+1)*sizeof(long long int));
   arr[0] = 0;
   arr[1] = 1;
   //printf("fib[%d] = %lld\n",0,arr[0]);
   //printf("fib[%d] = %lld\n",1,arr[1]);
   for (int i = 2; i<= n; i++) {
      arr[i] = arr[i-1] + arr[i-2];
      //printf("fib[%d] = %lld, ratio = %f\n",i,arr[i], arr[i]*1.0/arr[i-1]);
   }
   printf("fib[%d] = %lld, ratio = %f\n",n,arr[n], arr[n]*1.0/arr[n-1]);
   return 0;
}
