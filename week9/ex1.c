#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>     
#include <memory.h>

struct pFrame {
    int page;
    int cnt;
};

int main() {
    int n, p;
    float hit = 0, miss = 0;
    FILE* file = fopen("input.txt", "r");

    printf("Page numbers: ");
    scanf("%d", &n);

    struct pFrame frames[n];

    for (int i = 0; i < n; i ++) {
        frames[i].page = -1;
        frames[i].cnt = 0;
    }
    while(fscanf(file, "%d", &p) == 1) {
        if (p < 0) break;
        int pFound = -1;
        for (int i = 0; i < n; i ++) {
            if (frames[i].page == p) {
                pFound = i;
                break;
            }
        }
        if (pFound == -1) {
            int oldestPage;
            int mn = __INT32_MAX__;
            for (int i = 0; i < n; i ++) {
                if (frames[i].page == -1) {
                    oldestPage = i;
                    break;
                }
                if (frames[i].cnt < mn) {
                    mn = frames[i].cnt;
                    oldestPage = i;
                }
            }
            frames[oldestPage].cnt = 0;
            frames[oldestPage].page = p;
            miss += 1.0;
        }else{
            frames[pFound].cnt |= (1 << 8);
            hit += 1.0;
        }
    }
    printf("Hit %f, Miss %f", hit, miss);
    fclose(file);
}