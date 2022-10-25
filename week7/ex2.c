#include <stdio.h>
#include <stdlib.h>

int main(){ 
    int n;
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i ++){
        arr[i] = i;
        printf("%d ", arr[i]);
    }
    free(arr); 
	return EXIT_SUCCESS;
} 