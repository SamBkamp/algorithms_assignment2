#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mergesort.h"
#include "./debug.h"

void mergeSort(int *list, int end){ //this code was written under the influence of considerable amounts of stimulants i apologise to whoever has to try and make sense of this lol
  if(end == 1) return;
  int half = end >> 1; //shift right = div by 2. faster than division

  mergeSort(list, half);
  mergeSort(list+half, end-half);

  int* rightSide = list+half;
  int merged[end]; //new merged list
  int i = 0;//indeces for keeping track of all numbers
  int Li = 0;
  int Ri = 0;
while(i < end){
  if(Ri == end-half || (list[Li] < rightSide[Ri] && Li < half)){
    merged[i] = list[Li];
    Li++;
  }else{
    merged[i] = rightSide[Ri];
    Ri++;
  }
  i++;
 }

 for (int i = 0; i < end; i++){ //replace unordered list with ordered merged list
   list[i] = merged[i];
 }
}

