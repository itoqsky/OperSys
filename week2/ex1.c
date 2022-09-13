#include<stdio.h>
#include <float.h>
#include <limits.h>

int main (){
    int integer = INT_MAX;
    unsigned short int unsi = USHRT_MAX;
    long long ll = LONG_MAX;
    float f = FLT_MAX;
    double d = DBL_MAX;
    printf("Integer: %d; Size: %lu\n", integer, sizeof(integer));

    printf("Unsigned short int: %hu; Size: %lu\n", unsi, sizeof(unsi));

    printf("Long long int: %lld; Size: %lu\n", ll, sizeof(ll));

    printf("Float: %f; Size: %lu\n", f, sizeof(f));

    printf("Double: %lf; Size: %lu", d, sizeof(d));
}   