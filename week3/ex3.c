#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct Directory;
struct File;

int cnt = 0;

struct File{
    int id;
    char name[63];
    unsigned long int size;
    char data[1024];
    struct Directory * directory;// The parent directory
};

struct Directory{
    int nf;
    int nd;
    struct File files[256];
    struct Directory *directories[8];
    char path[2048];
    char name[63];
};

typedef struct Directory Directory;
typedef struct File File;


// Operations on files
void add_to_file(File *file, const char * content);
void append_to_file(File *file, const char * content);
void pwd_file(File * file);


// Operations on directories
void add_file(File* file, Directory *dir);
void add_dir(Directory *dir1, Directory *dir2); // given to you

// Helper functions
void show_dir(Directory *dir, int indent);
void show_file(File *file);
void show_file_detailed(File *file);

int main(){
    
    char content1[] = "int printf(const char * format, ...);";
    char content2[] = "int main(){printf('Hello World');}";
    char content3[] = "//This is a comment in C language";
    char content4[] = "Bourne Again Shell!";
    
    
    
    Directory home={.path = "home"}, bin={.path = "bin"}, root={.path = "/"};
    // Directory dir1={.path="dir1"};

    // Add subdirectories
    add_dir(&home, &root);
    add_dir(&bin, &root);
    // add_dir(&dir1, &home);
    
    File bash={.name = "bash"}, ex31={.name = "ex3_1.c"}, ex32={.name = "ex3_2.c"};
    
    add_file(&bash, &bin);
    add_file(&ex31, &home);
    add_file(&ex32,  &home);

    add_to_file(&bash, content4);
    add_to_file(&ex31, content1);
    add_to_file(&ex32, content1);
    
    append_to_file(&ex31, content2);

    show_dir(&root, 0);

    show_file_detailed(&bash);
    show_file_detailed(&ex31);
    show_file_detailed(&ex32);

    pwd_file(&bash);
    pwd_file(&ex31);
    pwd_file(&ex32);

    // clear(&root);
    
    return EXIT_SUCCESS;
}

// Helper functions

// Displays the content of the Directory dir

void show_dir(Directory *dir, int indent){
    char space[indent];
    for (int i = 0; i < indent; i ++){
        space[i] = ' ';
    }
    space[indent] = '\0';
    if(strlen(space) < 1) strcpy(space, " ");
    printf("\n%sDIRECTORY\n", space);
    printf("%s  path: %s\n", space, dir->path);
    printf("%s  files:\n", space);
    printf("%s    [ ", space);
    for (int i = 0; i < dir->nf; i ++){
        show_file(&dir->files[i]);
    }
    printf("]\n");
    printf("%s  directories:\n", space);
    printf("%s  { ", space);
    for (int i = 0; i < dir->nd; i ++){
        show_dir(dir->directories[i], 2 * (indent + 1) + 2);
    }
    if(!dir->nd) printf("}\n");
    else printf("%s  }", space);
}

// Prints the name of the File file
void show_file(File *file){
    printf("%s ", file->name);
}

// Shows details of the File file
void show_file_detailed(File *file){
    printf("\nFILE\n");
    printf(" id: %d\n", file->id);
    printf(" name: %s\n", file->name);
    printf(" size: %lu\n", file->size);
    printf(" data:\n");
    printf("    [ %s ]\n", file->data);
}



// Implementation: Operations on files

// Adds the content to the File file
void add_to_file(File *file, const char * content) {
    if(file){
        strlcpy(file->data, content, 1024 - 1);
        file->size = strlen(content);
    }
}

// Appends the content to the File file
void append_to_file(File *file, const char * content) {
    if (file && content){
        strlcat(file->data, content, 1024 - strlen(file->data) - 1);
        file->size += strlen(content);
    }
}

// Prints the path of the File file
void pwd_file(File * file) {
	// Example: the path for bash file is /bin/bash
    printf("%s/%s\n", file->directory->path, file->name);
}


// Implementation: Operations on directories

// Adds the File file to the Directory dir
void add_file(File* file, Directory *dir) {
	if (file && dir){
		dir->files[dir->nf] = *file;
        file->directory = dir;
		dir->nf++;
        file->id = ++cnt;
	}
}

// Given to you
// Adds the subdirectory dir1 to the directory dir2
void add_dir(Directory *dir1, Directory *dir2){
	if (dir1 && dir2){
		dir2->directories[dir2->nd] = dir1;
		dir2->nd++;
        char str[2048];
        strlcpy(str, dir2->path, 2048 - 1);
        if(strcmp(dir2->path, "/")) strlcat(str, "/", 2048 - strlen(str) - 1);
        strlcat(str, dir1->path, 2048 - strlen(str) - 1);
        strlcpy(dir1->path, str, 2048 - 1);
	}
}


