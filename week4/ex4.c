#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
    char str[256];
    while (fgets(str, 256, stdin)) system(str);
	return EXIT_SUCCESS;
}
