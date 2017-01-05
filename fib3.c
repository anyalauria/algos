#include <stdio.h>
#include <stdlib.h>

long long int *arr;
long long int fibo(int i) {
   if(arr[i] != -1) return arr[i];
   arr[i] = fibo(i-1) + fibo(i-2);
   return arr[i];
}
int main(int argc, char **argv) {
   int n;
   if (argc == 2)
      n = atoi(argv[1]); 
   arr = (long long int *) malloc((n+1) * sizeof(long long int));
   arr[0] = 0; arr[1] = 1;
   for (int i = 2; i <= n; i++) arr[i] = -1; 
   printf("fibo[%d] = %lld\n", n, fibo(n));
   return 0;
}
