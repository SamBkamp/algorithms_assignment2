#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "heapsort.h"
#include "debug.h"

void heapSort(int* list, int len){
  if(len == 1) return;
  //STEP 1: turn list into valid max heap
  for (int i = len-1; i > 0; i-=2){ //if parent node is missing child node then skip child nodes
    if(i == len-1 && len %2 == 0){
      i+=1;
      continue;
    }
    //to get the parent node its (x-2)>>1 or (x-1)>>1 for right and left child resp.
    int constant = list[i] < list[i-1] ? 1 : 2; //set constant depending if left or right child is larger
    int parent = (i-constant) >> 1;
    if(list[i-(2-constant)] > list[parent]){ //XOR swap
      list[parent] = list[parent]^list[i-(2-constant)];
      list[i-(2-constant)] = list[parent]^list[i-(2-constant)];
      list[parent] = list[parent]^list[i-(2-constant)];
    }
  }  

  //STEP 2: swap biggest and last, then decrease size of heap
  //xor swap
  list[0] = list[0] ^ list[len-1];
  list[len-1] = list[0] ^ list[len-1];
  list[0] = list[0] ^ list[len-1]; 
  heapSort(list, len-1);
}
