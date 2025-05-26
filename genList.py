#!/bin/python3

import random
import sys

amount = 500000

if(len(sys.argv) < 2):
    print("usage: "+sys.argv[0]+" random|reverse|duplicate|extreme")
    exit(0)

print("#include <stdlib.h>")
print("#include \"inputs.h\"")
print("int* inputs(int len){")
print("  int* list = malloc(sizeof(int) * len);")
    
if sys.argv[1] == "random":
    for i in range(0, amount):
        print("  list["+str(i)+"] = "+str(random.randint(0, 800))+";")

if sys.argv[1] == "reverse":
    for i in range(0, amount):
        print("  list["+str(i)+"] = "+str(amount-i)+";")

if sys.argv[1] == "duplicate":
    for i in range(0, amount):
        maxN = 800
        if(i%3==0 and i > 0): #every 3rd element will be duplicate
            maxN = i-1
        print("  list["+str(i)+"] = "+str(random.randint(0, maxN))+";")

if sys.argv[1] == "extreme":
    for i in range(0, amount):
        maxN = 300
        minN = 0
        if(i%10==0 and i > 0): #every 10th element will be an extreme value
            maxN = 800
            minN = 300
        print("  list["+str(i)+"] = "+str(random.randint(minN, maxN))+";")

        
print("  return list;")
print("}")
