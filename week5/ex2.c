#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>

// <WRITE YOUR CODE HERE>

struct Thread{
    pthread_t id;
    int i;
    char msg[256];
}thread[10001];

void* routine(void *arg){
    int i = *(int *)arg;
    printf("Thread %d is created!\n", i);
    printf("Thread %d's id - %d\n", i, thread[i].id);
    sprintf(thread[i].msg, "Hello from thread %d", i);
    printf("Thread %d prints - %s\n", i, thread[i].msg);

}

int main(){
    int n;
    scanf("%d", &n);
    struct Thread thread[n];
    for (int i = 0; i < n; i ++){
        pthread_create(&thread[i].id, NULL, &routine, &i);
        thread[i].i = i;
        pthread_join(thread[i].id, NULL);
            
        printf("Thread %d exits\n", i);
    }
	return EXIT_SUCCESS;
}