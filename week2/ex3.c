#include<stdio.h>
#include<string.h>

const int MOD = 1e9 + 7;

long long binpow(int a, int n){
    if(n == 0) return 1;
    if(n % 2 == 0){
        long long b = binpow(a, n / 2) % MOD;
        return b * b;
    }
    return binpow(a, n - 1) % MOD * a % MOD;
}

// void swap(char *x, char *y){
//     char temp = *x;
//     *x = *y;
//     *y = temp;
// }

// void reverse(char* arr){
//     int n = strlen(arr) - 1;
//     for (int i = 0; i <= n/2; i ++){
//         swap(arr + i, arr + (n - i));
//     }
// }

void convert(char* from, int s, int t){
    long long dec;
    int indx = 0;
    // reverse(from);
    int n = strlen(from) - 1;
    for (int i = 0; i <= n/2; i ++){
        char temp = from[i];
        from[i] = from[n - i];
        from[n - i] = temp;
    }
    while (from[indx]){
        dec += ((binpow(s, indx)) * (from[indx] - '0'));
        indx ++;
    }
    char to[33] = {};
    while (dec){
        int x = dec % t;
        sprintf(to + strlen(to), "%d", x);
        dec /= t;
    }
    // reverse(to);
    // printf("%lu", strlen(to));
    n = strlen(to) - 1;
    for (int i = 0; i <= n/2; i ++){
        char temp = to[i];
        to[i] = to[n - i];
        to[n - i] = temp;
    }
    printf("%s", to);
}

int main (){
    char from[33];
    int s, t;
    scanf("%s", from);
    scanf("%d", &s);
    scanf("%d", &t);
    convert(from, s, t);    
    return 0;
}   