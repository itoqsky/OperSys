#include<stdio.h>

int main (){
    char ch;
    char string[257];
    int n = 0;
    while((ch = getc(stdin)) != '.'){
        string[n] = ch;
        n ++;
    }
    printf("\"");
    for (int i = n; i >= 0; i --){
        printf("%c", string[i]);
    }
    printf("\"");
    return 0;
}   