#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debug.h"
#include "mergesort.h"
#include "heapsort.h"
#include "quicksort.h"
#include "insertionsort.h"


int main(int argc, char* argv[]){
  int* list = malloc(sizeof(int) * IN_LEN);
  list[0] = 9;
  list[1] = 4;
  list[2] = 3;
  list[3] = 8;
  list[4] = 10;
  
  list[5] = 2;
  list[6] = 5;
  list[7] = 15;
  list[8] = 50;
  list[9] = 60;
  
  

  int* quickList = malloc(sizeof(int) * IN_LEN);
  memcpy(quickList, list, sizeof(int) * IN_LEN);
  int* mergeList = malloc(sizeof(int) * IN_LEN);
  memcpy(mergeList, list, sizeof(int) * IN_LEN);
  int* heapList = malloc(sizeof(int) * IN_LEN);
  memcpy(heapList, list, sizeof(int) * IN_LEN);
  int* insertionList = malloc(sizeof(int) * IN_LEN);
  memcpy(insertionList, list, sizeof(int) * IN_LEN);

  printf("QUICK SORT:\n");
  printList(quickList);
  quickSort(quickList, 0, IN_LEN-1);
  printList(quickList);

  printf("MERGE SORT:\n");
  printList(mergeList);
  mergeSort(mergeList, IN_LEN-1);
  printList(mergeList);

  printf("HEAP SORT:\n");
  printList(heapList);
  heapSort(heapList, IN_LEN);
  printList(heapList);

  printf("INSERTION SORT:\n");
  printList(insertionList);
  insertionSort(insertionList, IN_LEN, 0);
  printList(insertionList);
  
  
  free(list);
  free(quickList);
  free(mergeList);
  free(heapList);
  free(insertionList);
}
