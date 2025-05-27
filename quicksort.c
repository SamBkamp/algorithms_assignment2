#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "quicksort.h"
#include "insertionsort.h"
#include "debug.h"

void quickSort(int* list, int start, int end){
  if(start == end) return;  
  int pivot = list[end-1];  
  int i = start;
  for (int j = start; j < end; j++){
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
  quickSort(list, start, i);//left hand side
  quickSort(list, i+1, end);//right hand side
}

void quickInsertSort(int* list, int start, int end){
  int pivot = list[end-1];  
  int i = start;
  for (int j = start; j < end; j++){
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
  
  if(i-start < (IN_LEN>>2)){
    insertionSort(list, i, start);
  }else{
    quickInsertSort(list, start, i);//left hand side
  }
  if(i-end < (IN_LEN>>2)){
    insertionSort(list, end, i+1);
  }else{
    quickInsertSort(list, i+1, end);//right hand side
  }
}
