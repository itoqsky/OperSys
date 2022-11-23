#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

#define ERROR 1
#define SUCCES 0

int main (){
    //FILE *output = fopen("ex2.txt", "a");

    DIR *dirp = opendir("/");
    struct dirent *dep;

    if(dirp == NULL) return ERROR;

    printf("Output:-----------------------\n");

    while((dep = readdir(dirp)) != NULL){
        printf("%s\n", dep->d_name);
    }
    closedir(dirp);
    return SUCCES;
}