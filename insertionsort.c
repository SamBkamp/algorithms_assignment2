#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "insertionsort.h"
#include "debug.h"

void insertionSort(int* list, int len, int key){
  if(key == len) return;
  int keyVal = list[key];
  int j = key-1;
  while(keyVal < list[j] && j >= 0){
    list[j+1] = list[j];
    j = j-1;
  }
  list[j+1] = keyVal;
  insertionSort(list, len, key+1);
}
