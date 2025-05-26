#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<sys/time.h>

#include "debug.h"
#include "inputs.h"
#include "mergesort.h"
#include "heapsort.h"
#include "quicksort.h"
#include "insertionsort.h"
#include "selectionsort.h"


int main(int argc, char* argv[]){

  int* list = inputs(IN_LEN);
    
  struct timeval stop, start;

  printf("list size: %d elements\n", IN_LEN);
  
  //alloc
  int* quickList = malloc(sizeof(int) * IN_LEN);
  memcpy(quickList, list, sizeof(int) * IN_LEN);    
  //printList(quickList);
  gettimeofday(&start, NULL);
  quickSort(quickList, 0, IN_LEN);
  gettimeofday(&stop, NULL);
  //printList(quickList);
  printf("QUICK SORT TOOK %ld MS\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);
  //dealloc
  free(quickList);  
  
  //alloc
  int* mergeList = malloc(sizeof(int) * IN_LEN);
  memcpy(mergeList, list, sizeof(int) * IN_LEN);
  //printList(mergeList);
  gettimeofday(&start, NULL);
  mergeSort(mergeList, IN_LEN);
  gettimeofday(&stop, NULL);
  //printList(mergeList);
  printf("MERGE SORT TOOK %d MS\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);
  //dealloc
  free(mergeList);
  
  int* heapList = malloc(sizeof(int) * IN_LEN);
  memcpy(heapList, list, sizeof(int) * IN_LEN);
  //printList(heapList);
  gettimeofday(&start, NULL);
  heapSort(heapList, IN_LEN);
  gettimeofday(&stop, NULL);
  //printList(heapList);
  printf("HEAP SORT TOOK %d MS\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);
  free(heapList);

  int* insertionList = malloc(sizeof(int) * IN_LEN);
  memcpy(insertionList, list, sizeof(int) * IN_LEN);
  //printList(insertionList);
  gettimeofday(&start, NULL);
  insertionSort(insertionList, IN_LEN, 0);
  gettimeofday(&stop, NULL);
  //printList(insertionList);
  printf("INSERTION SORT TOOK %d MS\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);
  free(insertionList);

  int* selectionList = malloc(sizeof(int) * IN_LEN);
  memcpy(selectionList, list, sizeof(int) * IN_LEN);
  //printList(selectionList);
  gettimeofday(&start, NULL);
  selectionSort(selectionList, IN_LEN, 0);
  gettimeofday(&stop, NULL);
  //printList(selectionList);
  printf("SELECTION SORT TOOK %d MS\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);
  free(selectionList);

  printf("------------------------\n");
  
  free(list);    
}
