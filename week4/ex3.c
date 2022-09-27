#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[]){
    pid_t pid;
    int n;
    n = atoi(argv[1]);
    while(n --){
        pid = fork();
        sleep(5);
    }
	return EXIT_SUCCESS;
}