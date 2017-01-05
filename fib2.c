#include <stdio.h>
#include <stdlib.h>

long long int fibo(int i) {
   if (i == 0 || i == 1) 
      return i;
   else
      return (fibo(i-1) + fibo(i-2));
}
int main(int argc, char **argv) {
   int n;
   if (argc == 2)
      n = atoi(argv[1]); 
   printf("fibo[%d] = %lld\n", n, fibo(n));
   return 0;
}
