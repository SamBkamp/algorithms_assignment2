#!/bin/bash

./genList.py extreme > inputs.c
gcc *.c
./a.out >> stats
