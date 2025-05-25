#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "quicksort.h"
#include "debug.h"

void quickSort(int* list, int start, int end){

  if(start == end) return;

  
  int pivot = list[end-1];  
  int i = 0;
  for (int j = 0; j < end; j++){
    if(list[j] < pivot){
      int swap = list[j];
      list[j] = list[i];
      list[i] = swap;
      i++;
    }
  }
  int swap = list[end-1];
  list[end-1] = list[i];
  list[i] = swap;
  quickSort(list, start, i);
  quickSort(list, i+1, end);
}

