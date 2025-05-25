#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "insertionsort.h"
#include "debug.h"


void insertionSort(int* list, int len, int key){
  if(key == len) return;
  int j = key;
  while(list[key] < list[j-1] && j >= 0){
    j--;
  }
  int temp = list[key];
  for (int k = key-1; k >= j; k--){
    list[k+1] = list[k];
  }
  list[j] = temp;
  insertionSort(list, len, key+1);
}
