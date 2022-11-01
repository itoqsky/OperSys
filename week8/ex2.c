#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 

int *ptr; 

int main() {
    for(int i = 1 ; i <= 10 ; i ++) {
        ptr = malloc(10485760);
        memset(ptr, 0, 10485760);
        sleep(1) ;
    }
    free(ptr) ;
    return 0;
}
// Swapins and Swapouts are always zero
// free memory was decresing for 10 seconds then after started increasing.
//