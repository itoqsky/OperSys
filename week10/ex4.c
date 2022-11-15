#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

#define ERROR 1
#define SUCCES 0

typedef struct {
    ino_t inode;
    nlink_t links;
    char name[32];
    char lnames[256];
}File;

int main (){
    FILE *output = fopen("ex4.txt", "w");

    int cnt = 0;
    File files[256];
    struct stat stats;
    DIR *dirp = opendir("tmp");
    struct dirent *dep;

    if(dirp == NULL) return ERROR;

    while((dep = readdir(dirp)) != NULL){

        char fname[32];
        strcpy(fname, "tmp/");
        strcat(fname, dep->d_name);
        
        int found = 0;

        if(stat(fname, &stats) != 0) return ENOENT;
        
        strcpy(files[cnt].name, dep->d_name);
        strcpy(files[cnt].lnames, dep->d_name);
        files[cnt].inode = stats.st_ino;
        files[cnt].links = 1;

        for (int i = 0; i < cnt; i ++){
            if(files[i].inode == files[cnt].inode){
                strcat(strcat(files[cnt].lnames, ", "), files[i].name);
                strcat(strcat(files[i].lnames, ", "), files[cnt].name);
                files[cnt].links ++;
                files[i].links ++;
            }
        }
        cnt ++;
    }
    closedir(dirp);
    fprintf(output, "FILE --- HARD LINKS\n");
    for(int i = 0; i < cnt; i ++)
        if(files[i].links >= 2) {
            fprintf(output, "%s --- %s\n", files[i].name, files[i].lnames);
        }
    return SUCCES;
}