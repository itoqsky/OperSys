#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>

struct tm *timeinfo;
time_t timer;

int foo(int age){
    int res = timeinfo->tm_year + 1900 - age;
    return res;
}

int main (){
    const int x = 10;
    int *pt = (int*)&x, a[5];
    time(&timer);
    timeinfo = localtime(&timer);
    const int *const ptr = malloc(5 * sizeof(int));
    pt = (int *)ptr;
    for (int i = 0; i < 5; i ++){
        pt[i] = x;
        printf("%p\n", &pt[i]);
    }
    for (int i = 0; i < 5; i ++){
        scanf("%d", &a[i]);
        pt[i] = a[i];
    }
    for (int i = 0; i < 5; i ++){
        pt[i] = a[i];
        printf("%d\n", foo(pt[i]));
    }
    free((int *)ptr);
    
    return EXIT_SUCCESS;
}   