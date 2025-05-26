#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "heapsort.h"
#include "debug.h"

void maxHeapify(int* list, int i, int len) {
    int largest = i; // Start with the current node
    int l = (i << 1) + 1; // Left child index
    int r = (i << 1) + 2; // Right child index

    // Check if left child exists and is greater than current largest
    if (l < len && list[l] > list[largest]) {
        largest = l;
    }

    // Check if right child exists and is greater than current largest
    if (r < len && list[r] > list[largest]) {
        largest = r;
    }

    // If largest is not the current node, swap and recurse
    if (largest != i) {
        // Swap the current node with the largest child
        int temp = list[i];
        list[i] = list[largest];
        list[largest] = temp;

        maxHeapify(list, largest, len);
    }
}
void heapSort(int* list, int len){
  if(len == 1) return;
  //step 1: max heap  - bubble up largest values  
  maxHeapify(list, 0, len);
 
  
  //STEP 2: swap biggest and last, then decrease size of heap
  //xor swap
  list[0] = list[0] ^ list[len-1];
  list[len-1] = list[0] ^ list[len-1];
  list[0] = list[0] ^ list[len-1];
  heapSort(list, len-1);
  
}
