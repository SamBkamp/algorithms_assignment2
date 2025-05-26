#include <stdlib.h>
#include "inputs.h"
int* inputs(int len){
  int* list = malloc(sizeof(int) * len);
  list[0] = 164;
  list[1] = 404;
  list[2] = 647;
  list[3] = 451;
  list[4] = 414;
  return list;
}
