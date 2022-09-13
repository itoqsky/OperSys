#include<stdio.h>

int main (){
    int n = 7;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= i; j ++){
            printf("*");
        }
        printf("\n");
    }
    int x = (n + 1) / 2;
    printf("\n");
    for (int i = 1; i <= n; i ++){
        if(i <= (n + 1) / 2){
            for (int j = 1; j <= i; j ++){
                printf("*");
            }
            printf("\n");
        }else{
            x --;
            for (int j = 1; j <= x; j ++){
                printf("*");
            }
            printf("\n");
        }
    }
    printf("\n");
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            printf("*");
        }
        printf("\n");
    }
    return 1;
}   