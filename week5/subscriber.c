#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(){
    int fd;
    char *ex1 = "/tmp/ex1";
    char msg[1024];

    mkfifo(ex1, 0666);

    while (1){
        fd = open(ex1, O_RDONLY);
        read(fd, msg, 1024);
        
        printf("Publisher: %s\n", msg);
        close(fd);
        sleep(1);
    }
    return EXIT_SUCCESS;
}