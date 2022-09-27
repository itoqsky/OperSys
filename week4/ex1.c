#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>


// <WRITE YOUR CODE HERE>



int main(void){

    clock_t t, t1, t2;
    t = clock();

    pid_t pid = fork();    
    t1 = clock(); 
    if(pid == 0){
	    printf("-first\n  child id: %d, parent id: %d, and it took %lf milliseconds\n", getpid(), getppid(), ((double)(clock() - t1))/CLOCKS_PER_SEC * 1000);
        exit(0);
    }
    pid = fork();
    t2 = clock();
    if(pid == 0){
	    printf("-second\n  child id: %d, parent id: %d, and it took %lf milliseconds\n", getpid(), getppid(), ((double)(clock() - t2))/CLOCKS_PER_SEC * 1000);
        exit(0);
    }
    printf("parent id: %d and it took %lf milliseconds\n", getpid(), ((double)clock() - t)/CLOCKS_PER_SEC * 1000);

    wait(0);
    // while (wait(0)) exit(0);
	return EXIT_SUCCESS;

}