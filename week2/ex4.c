#include<stdio.h>
#include<string.h>
#include <ctype.h>


const int MOD = 1e9 + 7;

int ok = 0;

char str[50001], used[50001], used1[50001];

int count(char lt){
    return used1[lt]-'0';
}

void countAll(){
    for (int i = 0; i < strlen(str); i ++){
        if(i == strlen(str) - 1){
            printf("%c:%d", str[i], used[str[i]] - '0');
            break;
        }
        printf("%c:%d, ", str[i], used[str[i]] - '0');
    }
}

int main (){
    // scanf("%s", str);
    char word[50001], lt;
    scanf("%[^\n]", str);
    for(int i = 0; str[i]; i++){
        str[i] = tolower(str[i]);
    }
    for (int i = 0; i < 50001; i ++){
        used[i] = used1[i] = '0';
    }
    for (int i = 0; i < strlen(str); i ++){
        used[str[i]]++;
    }
    for (int i = 0; i < strlen(str); i ++){
        if(str[i] == ',') {
            ok = 1;
            break;
        }
    }
    if(ok == 1){
        sscanf(str, "%[^,]", word);
        for (int i = 0; i < strlen(str); i ++){
            used1[word[i]] ++;
        }
        lt = str[strlen(str) - 1];
        printf("%c:%d", lt, count(lt));
    }else{
        countAll();
    }
    // printf("%s_%c", word, lt);
    return 0;
}   