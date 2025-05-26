#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "insertionsort.h"
#include "debug.h"


void insertionSort(int* list, int len, int key){
  if(key == len) return;
  int j = key;
  while(list[key] < list[j-1] && j >= 0){
    list[j+1] = list[j];
    j--;
  }
  
  list[j] = list[key];
  insertionSort(list, len, key+1);
}
