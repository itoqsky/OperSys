#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *reallocc(void *p, size_t old_sz, size_t new_sz){
    void *new_p = malloc(new_sz);
    memcpy(new_p, p, new_sz);
    free(p);
    return new_p; 
}

int main(){
    int n;
    scanf("%d", &n);
    int *ptr = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i ++){
        ptr[i] = n;
        printf("%d ", ptr[i]);
    }
    printf("\n");
    
    int m;
    scanf("%d", &m);
    ptr = reallocc(ptr, sizeof(int) * n, sizeof(int) * m);
    for (int i = 0; i < m; i ++){
        ptr[i] = m;
        printf("%d ", ptr[i]);
    }
	return EXIT_SUCCESS;
}