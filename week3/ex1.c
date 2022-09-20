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
    int *pt = &x, a[5];
    time(&timer);
    timeinfo = localtime(&timer);
    const int *const ptr = malloc(5 * sizeof(int));
    pt = ptr;
    for (int i = 0; i < 5; i ++){
        pt[i] = x;
        printf("%p\n", &pt[i]);
    }
    // scanf("%d%d%d%d", s1, s2, s3, s4);
    for (int i = 0; i < 5; i ++){
        scanf("%d", &a[i]);
        pt[i] = a[i];
    }
    for (int i = 0; i < 5; i ++){
        pt[i] = a[i];
        printf("%d\n", foo(a[i]));
    }
    
    free(ptr);
    return EXIT_SUCCESS;

}   