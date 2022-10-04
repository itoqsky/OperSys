#!/bin/sh
gcc -pthread ex4.c
/usr/bin/time ./a.out 10000000 1 2> ex3.txt
/usr/bin/time ./a.out 10000000 2 2>> ex3.txt
/usr/bin/time ./a.out 10000000 4 2>> ex3.txt
/usr/bin/time ./a.out 10000000 10 2>> ex3.txt
/usr/bin/time ./a.out 10000000 100 2>> ex3.txt