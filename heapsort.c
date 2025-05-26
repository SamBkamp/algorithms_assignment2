#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "heapsort.h"
#include "debug.h"


void maxHeapMaker(int* list, int i,int len){

  int l = (i<<1)+1; //left hand side (i*2 + 1)
  int r = (i<<1)+2; //right hand side (i*2 + 2)
  
  if(l > len-1 || r > len-1) 
    return; //means we're at leaf node
  

  maxHeapMaker(list, l, len);
  maxHeapMaker(list, r, len);
  
  int larger = list[l] > list[r] ? l : r;//get larger of the two children
  
  if(list[larger] > list[i]){
    //swap largest child with parent
    list[larger] = list[larger]^list[i];
    list[i] = list[larger]^list[i];
    list[larger] = list[larger]^list[i];
  }        
}

void heapSort(int* list, int len){
  if(len == 1) return;
  //step 1: max heap  - bubble up largest values  
  maxHeapMaker(list, 0, len);
 
  
  //STEP 2: swap biggest and last, then decrease size of heap
  //xor swap
  list[0] = list[0] ^ list[len-1];
  list[len-1] = list[0] ^ list[len-1];
  list[0] = list[0] ^ list[len-1];
  heapSort(list, len-1);
  
}
