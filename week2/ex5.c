#include<stdio.h>

long long tribonacci(long long x){
    long long a = 0, b = 1, c = 1, num = 0;
    if(x >= 3){
        while((x --) >= 3){
            num = (a + b + c);
            a = b;
            b = c;
            c = num;
        }
        return num;
    }else{
        if(x == 0){
            return 0;
        }else{
            return 1;
        }
    }
}
int main (){
    printf("%lld\n", tribonacci(4));
    printf("%lld", tribonacci(36));
    return 0;
}   