#include <stdio.h>
#include <stdlib.h>


void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*));

void* addInt(const void* a, const void* b){
    int *ptr1 = (int *)a;
    int *ptr2 = (int *)b;
    *ptr1 += *ptr2;
    return ptr1;
}

void* addDouble(const void* a, const void* b){
    double *ptr1 = (double *)a;
    double *ptr2 = (double *)b;
    *ptr1 += *ptr2;
    return ptr1;
}

void* mulInt(const void* a, const void* b){
    int *ptr1 = (int *)a;
    int *ptr2 = (int *)b;
    *ptr1 *= *ptr2;
    return ptr1;
}

void* mulDouble(const void* a, const void* b){
    double *ptr1 = (double *)a;
    double *ptr2 = (double *)b;
    *ptr1 *= *ptr2;
    return ptr1;
}

void* meanInt(const void* a, const void* b){
    int *res = malloc(sizeof(int));
    for (int i = 0; i < (*(int*)b); i ++){
        addInt((int*)res, (int*)a + i);
    }
    *res /= *(int*)b;
    return res;
}

void* meanDouble(const void* a, const void* b){
    double *res = malloc(sizeof(double));
    for (int i = 0; i < (*(int*)b); i ++){
        addDouble((double*)res, (double*)a + i);
    }
    *res /= *(int*)b;
    return res;
}

void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*)){

	void* output;
	if (size==sizeof(int)){ // base is a pointer to an integer
        output = (int*)initial_value;
        if(opr == meanInt){
            output = opr((int*)base, &n);
        }else{
            for (int i = 0; i < n; i ++){
                opr((int*)output, (int*)base + i);
            }
        }
	}else{ // base is a pointer to a double
        output = (double*)initial_value;
        if(opr == meanDouble){
            output = opr((double*)base, &n);
        }else{
            for (int i = 0; i < n; i ++){
                opr((double*)output, (double*)base + i);
            }
        }
	}

	return output;
}

int main(){

        int *ints = malloc(sizeof(int) * 5);
        for (int i = 0; i < 5; i ++){
            ints[i] = i + 1;
        }
        double* doubles = malloc(sizeof(double)*5);
        for (int i = 0; i < 5; i ++){
            doubles[i] = i + 1.1;
        }

        void* init_val = (int*)malloc(sizeof(int));

	// Addition

        *(int *)init_val = 0;
        int* result1a;
        result1a = (int *)aggregate(ints, sizeof(int), 5, init_val, &addInt);
        
        printf("%d\n", *result1a);

	    double* result2a = (double *)aggregate(doubles, sizeof(double), 5, init_val, &addDouble);
	
        printf("%f\n", *result2a);
                

	// Multiplication

        init_val = (double*)realloc(init_val, sizeof(double));
        *(int *)init_val = 1;

        int* result1m = (int *)aggregate(ints, sizeof(int), 5, init_val, &mulInt);
        
        printf("%d\n", *result1m);

        *(double *)init_val = 1;

	    double* result2m = (double *)aggregate(doubles, sizeof(double), 5, init_val, &mulDouble);

        printf("%f\n", *result2m);
        
	// Mean
	
        int* result1mean = (int *)aggregate(ints, sizeof(int), 5, init_val, &meanInt);
    
        printf("%d\n", *result1mean);

        double* result2mean = (double *)aggregate(doubles, sizeof(double), 5, init_val, &meanDouble);
	
        printf("%f\n", *result2mean);
	
        
    // free the pointers
        
        free(init_val);
        return EXIT_SUCCESS;
}
