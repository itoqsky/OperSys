#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

// Calculate the dot product of the vectors u and v from the component [start] till the component [end] exclusively.
int dotprod(int u[], int v[], int start, int end){

	int result = 0;
	
	for (int i=start; i<end; i++){
		result += u[i] * v[i];
	}
	
	return result;
}


int main(void){
    FILE * in = fopen("temp.txt", "r");
    FILE * out = fopen("temp.txt", "w");
    pid_t pid = getpid();
    int u[120], v[120], n;
    srand(time(0));
    for (int i = 0; i < 120; i ++){
        u[i] = rand() % 100;
        v[i] = rand() % 100;
    }
    scanf("%d", &n);
    int chunk = 120 / n;
    int uchunk = (120 / n) + (120%n);
    
    int st = 0, fn = 0;
    for (int i = 1; i <= n; i ++){
        st = fn;
        fn += chunk;
        pid = fork();
        if(pid == 0){
            fprintf(out, "%d\n", dotprod(u, v, st, fn));
            exit(0);
        }
    }
    int sum = 0;
    wait(0);
    while (n --){
        int x; 
        fscanf(in, "%d", &x);
        sum += x;
    }

    printf("%d", sum);
    fclose(out);
	return EXIT_SUCCESS;

}

/*
Example:
Assume that
u = [u1, u2, u3, u4]
v = [v1, v2, v3, v4]
k=1 ==> n = 2 processes
Equally distribute the dot product calculation task. We have multiple ways to distribute the task equally.
1- A possible task distribution is as follows:
First process will calculate dot product for the first two components
Second process will calculate dot product for the last two components
The computation result of the first process is u1 * v1 + u2 * v2 ==> c1
The computation result of the second process is u3 * v3 + u4 * v4 ==> c2
2- Another possible distribution is as follows:
First process will calculate dot product for the even components
Second process will calculate dot product for the odd components
The computation result of the first process is u2 * v2 + u4 * v4 ==> c1
The computation result of the second process is u1 * v1 + u3 * v3 ==> c2
The file temp.txt will contain as follows: (format is not restricted)
-------------------
c1
c2
-------------------
The "main" process will aggregate all dot product computations of its children
It will read the lines and aggregate.
c1 + c2 ==> result of u * v
*/