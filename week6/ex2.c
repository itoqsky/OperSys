#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>

int compare(const void* a, const void* b){
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;

    return 0;
}
   
int main(){
	int n;
	scanf("%d", &n);
	int at[n], bt[n], p[n], mna=1e18+1, mni= 0, mnb=1e18+1;
	for (int i = 0; i < n; i ++){
		scanf("%d", &at[i]);
		scanf("%d", &bt[i]);
		p[i] = i + 1;
        if(mna > at[i] && mnb > bt[i]){
            mna = at[i];
            mnb = bt[i];
            mni = i;
        }
	}
	int temp;
	int ct[n], wt[n], tat[n], used[10001]={0};
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < (n - i - 1); j ++){
			if(at[j] > at[j + 1]){
				temp = p[j + 1];
				p[j + 1] = p[j];
				p[j] = temp;
				temp = at[j + 1];
				at[j + 1] = at[j];
				at[j] = temp;
				temp = bt[j + 1];
				bt[j + 1] = bt[j];
				bt[j] = temp;
			}
		}
	}
    
    for(int i = 0; i < n; i ++){
		for(int j = 0; j < (n - i - 1); j ++){
			if(bt[j] > bt[j + 1]){
				temp = p[j + 1];
				p[j + 1] = p[j];
				p[j] = temp;
				temp = at[j + 1];
				at[j + 1] = at[j];
				at[j] = temp;
				temp = bt[j + 1];
				bt[j + 1] = bt[j];
				bt[j] = temp;
			}
		}
	}
    
	double a_tat = 0, a_wt = 0;
	ct[0] = at[0] + bt[0];
    used[0] = 1;
	for (int i = 1; i < n; i ++){
        ct[i] = ct[i - 1];
        for (int j = i; j < n; j ++){
            if(ct[i] >= at[j] && !used[j]){
                ct[i] += bt[j];
                used[j] = 1;
                break;
            }
        }
        if(ct[i] == ct[i - 1]){
            int temp = 0;
            if(ct[i - 1] < at[i]){
                temp = at[i] - ct[i - 1];
            }
            ct[i] = ct[i - 1] + bt[i] + temp;
        }
	}
    
	for (int i = 0; i < n; i ++){
		tat[i] = ct[i] - at[i];
		wt[i] = tat[i] - bt[i];
		a_tat += tat[i];
		a_wt += wt[i];
	}
	a_tat /= n;
	a_wt /= n;

	printf("p\t A.T\t B.T\t C.T\t TAT\t WT");

	for(int i = 0; i < n; i ++){
    	printf("\nP%d\t %d\t %d\t %d \t %d \t %d", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\naverage turnaround time is %lf",a_tat);
    printf("\naverage wating timme is %lf",a_wt);
	return EXIT_SUCCESS;
}