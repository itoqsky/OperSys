#include<stdio.h>
#include<string.h>

const int MOD = 1e9 + 7;

long long binpow(int a, int n){
    if(n <= 0) return 1;
    if(n % 2 == 0){
        long long b = binpow(a, n / 2) % MOD;
        return b * b;
    }
    return binpow(a, n - 1) % MOD * a % MOD;
}

void convert(long long num, int s, int t){
    long long dec = 0, pw = 1;
    if(s < 2 || s > 10 || t < 2 || t > 10){
        if(s < 2 || s > 10 || t < 2 || t > 10){
            printf("cannot convert!");
           return;
        }
    }
    while(num){
        if(num % 10 >= s){
            printf("cannot convert!");
            return;
        }
        dec += (num % 10) * pw;
        pw *= s;
        num /= 10;
    }
    char to[33] = {};
    while (dec){
        int x = dec % t;
        sprintf(to + strlen(to), "%d", x);
        dec /= t;
    }
    int n = strlen(to) - 1;
    for (int i = 0; i <= n/2; i ++){
        char temp = to[i];
        to[i] = to[n - i];
        to[n - i] = temp;
    }
    printf("%s", to);
}

int main (){
    long long from;
    int s, t;
    scanf("%lld", &from);
    scanf("%d", &s);
    scanf("%d", &t);
    convert(from, s, t);    
    return 0;
}   
