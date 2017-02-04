#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
   double x, y,z,t, diffx, diffy, diffz, distSq, distSq2 ;
   int numIter, count=0, count2=0;
   if(argc > 1) 
      numIter = atoi(argv[1]);
   else
      numIter = 1000000;
   for(int i=0; i<numIter; i++) {
      x = rand()/((double)RAND_MAX);
      y = rand()/((double)RAND_MAX);
      z = rand()/((double)RAND_MAX);
      diffx = x-0.5;
      diffy = y-0.5;
      diffz = z-0.5;
      distSq = diffx * diffx + diffy * diffy;
      distSq2 = diffx * diffx + diffy * diffy + diffz * diffz;
      if(distSq <= 0.25) 
         count++;
      if(distSq2 <= 0.25)
         count2++;
   }
   printf("Ratio = %10.8f %10.8f\n", (4.0*count)/numIter, (6.0*count2)/numIter);
   return 0;
}
