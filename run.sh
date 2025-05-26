#!/bin/bash

./genList.py random > inputs.c
gcc *.c
./a.out >> stats
