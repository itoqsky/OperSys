#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int *ptr; 

int main() {

    struct rusage r_usage;
    for(int i = 1; i <= 10; i ++) {
        ptr = malloc(10485760);
        memset(ptr, 0, 10485760);
        getrusage(RUSAGE_SELF,&r_usage);
        printf("Usage = %ld\n",r_usage.ru_maxrss);
        sleep(1) ;
    }
    free(ptr) ;
    return 0;
}