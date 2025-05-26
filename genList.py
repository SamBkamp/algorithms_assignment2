#!/bin/python3

import random
import sys

amount = 40000

if(len(sys.argv) < 2):
    print("usage: "+sys.argv[0]+" random")
    exit(0)

print("#include <stdlib.h>")
print("#include \"inputs.h\"")
print("int* inputs(int len){")
print("  int* list = malloc(sizeof(int) * len);")
    
if sys.argv[1] == "random":
    for i in range(0, amount):
        print("  list["+str(i)+"] = "+str(random.randint(0, 800))+";")

print("  return list;")
print("}")
