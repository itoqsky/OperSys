#include <stdio.h>
#include <stdlib.h>

int main(){

	double a_tat = 0, a_wt = 0;
    int n;

    scanf("%d", &n);

	int at[n], bt[n], p[n], exp[n];
	int ct, wt[n], tat[n], used[10001]={0};

	for (int i = 0; i < n; i ++){
		scanf("%d", &at[i]);
		scanf("%d", &bt[i]);
		p[i] = i + 1;
	}

    printf("Quantum: ");
    int qnt;
    scanf("%d", &qnt);
    for(int i = 0; i < n; i ++){
        int temp;
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
        printf("%d \t %d\n", at[i], bt[i]); 
	}
    for (int i = 0; i < n; i ++){
        exp[i] = bt[i];
    }
    int cnt = n;
    printf("\nProcess\t AT\t BT\t CT\t TAT\t WT");
    int i, ok = 0;
    for(ct = at[0], i = 0; cnt != 0;){  
        if(exp[i] <= qnt && exp[i] > 0){
            ct += exp[i];
            exp[i] = 0;
            ok = 1;
        }     
        else if(exp[i] > 0){  
            exp[i] -= qnt;  
            ct += qnt;  
        }
        if(ok && exp[i] == 0){  
            tat[i] = ct - at[i];
            wt[i] = tat[i] - bt[i];
            a_tat += tat[i];
            a_wt += wt[i];
            printf("\nP%d\t %d\t %d\t %d \t %d \t %d", p[i], at[i], bt[i], ct, tat[i], wt[i]); 
            ok = 0;    
            cnt --;
        }  
        if(i == n - 1){
            i = 0;
        }else if(at[i + 1] <= ct){
            i ++;
        }else{
            i = n - 1;
        } 
    }  
    a_tat /= n;
    a_wt /= n;
    printf("\nAverage turnaround time is %lf",a_tat);
    printf("\nAverage waiting time is %lf",a_wt);
    return 0;
}