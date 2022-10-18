#!/bin/bash

gcc -c utils.c -O2
gcc -c sort.c -O2
gcc -O2 -o main.out main.c utils.o sort.o
