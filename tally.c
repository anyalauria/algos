#include <stdio.h>
#include <stdlib.h> 

void tally_sort(int *arr, int n){

   int min = 0, max = 0; 

   for (int a = 0; a <= n; a++){
        if ( arr[a] > max) max = arr[a]
   }
   for (int b = 0; b <= n; b++){
        if ( arr[a] < min) min = arr[a]
   }

  int range = (max - min) + 1 
  int slots[range] = {0}; 
  
  for (int y = 0; y <= n; y++){
      count = arr[y] - min; 
      slots[count] = slots[count] + 1;
  }
  
  int outInd = 0;
  for (int z = 0; z < range; z++, min ++;){
      for (int x = 0; x < slots[range]; x++){
          arr[outInd] = min
          outInd++; 
      }
  }
  
  printf("The sorted array is:\n\n");
  for (int g = 0; g <= n; g++){
     printf(" "arr[g]" ");
  }   
       
}



int main (int argc, char**argv){

    int n;
    if (argc == 2)
       n = atoi(argv[1]); 
    arr = (int*) malloc((n+1) * sizeof(int));
    
    for (int i = 0; i <= n; i++){
        arr[i] = rand() % (n/10) + 1;
        } 

    tally_sort(arr**, n);
}

 
         


