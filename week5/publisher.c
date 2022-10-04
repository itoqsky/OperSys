#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[]){
    int fd;
    char *ex1 = "/tmp/ex1";
    char msg[1024];

    int n = atoi(argv[1]);

    mkfifo(ex1, 0666);

    while (1){
        fgets(msg, 1024, stdin);
        fd = open(ex1, O_WRONLY);
        for (int i = 0; i < n; i ++){
            write(fd, msg, 1024);
        }
        
        close(fd);
        sleep(1);
    }

    return EXIT_SUCCESS;
}