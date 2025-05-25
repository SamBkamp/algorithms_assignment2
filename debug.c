#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "debug.h"


void printMaxHeap(int* list, int len){
  int levels = (len-1)>>1; //a heap can only be odd and in the series 2x-1 (i think)
  printf("   %d\n", list[0]);
  for (int i = 1; i < levels; i++){
    for (int j = 0; j < 2<<(i-1); j++){
      for(int k = 0; k < levels - (2<<(i-1)); k++) printf(" ");
      printf("%d ", list[(2<<(i-1))-1+j]);
    }
    printf("\n");
  }
}


void printList_debug(int* list, int len){
  for (int i = 0; i < len; i++){
    printf("[%d] ", list[i]);
  }
  printf("\n");
}

void printList(int* list){
  for (int i = 0; i < IN_LEN; i++){
    printf("[%d] ", list[i]);
  }
  printf("\n");
}

