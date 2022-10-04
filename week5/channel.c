#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(){
    char msg[1024];
    char msg2[1024];
    int fd[2];
    pid_t pid;
    
    if (pipe(fd) == -1) {
        exit(1);
    }

    pid = fork();
    if(pid > 0){
        while (1){
            scanf("%s", msg);
            write(fd[1], msg, strlen(msg) + 1);
        }
    }else if(pid == 0){
        while (1){
            read(fd[0], msg2, 1024);
            printf("-> %s\n", msg2);
        }
    }else exit(1);

    return EXIT_SUCCESS;
}