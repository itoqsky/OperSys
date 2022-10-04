#!/bin/sh
gcc ex3.c
/usr/bin/time ./a.out 10000000 100 2>> ex3.txt
