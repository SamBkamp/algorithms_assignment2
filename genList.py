#!/bin/python3

import random
import sys

amount = 1000

if(len(sys.argv) < 2):
    print("usage: "+sys.argv[0]+" random")
    exit(0)

if sys.argv[1] == "random":
    print("#define IN_LEN " + str(amount))
    for i in range(0, amount):
        print("list["+str(i)+"] = "+str(random.randint(0, 800))+";")
