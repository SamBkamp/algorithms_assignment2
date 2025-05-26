#!/bin/python3

import random

amount = 1000
print("#define IN_LEN " + str(amount))

for i in range(0, amount):
    print("list["+str(i)+"] = "+str(random.randint(0, 800))+";")
