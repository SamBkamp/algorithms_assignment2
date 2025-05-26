#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debug.h"
#include "selectionsort.h"

void selectionSort(int* list, int len, int start){
  if(start == len) return;
  
  int lowest = start;
  for(int i = start+1; i < len; i++){
    if(list[i] < list[lowest])
      lowest = i;
  }
  if(lowest == start) goto next;
  //swap with lowest
  list[start] = list[start] ^ list[lowest];
  list[lowest] = list[start] ^ list[lowest];
  list[start] = list[start] ^ list[lowest];
 next:
  selectionSort(list, len, start+1);
}
