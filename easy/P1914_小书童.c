// Created by Glin on 2023/5/14.
#include "stdio.h"
#include "string.h"

int main(){
    int n;
    char s[51] = {'\0'};
    scanf("%d", &n);
    scanf("%s", s);

    for (int i = 0; i < strlen(s); ++i) {
        s[i] = (s[i]+n-'a')%26 + 'a';
    }
    printf("%s", s);
    return 0;
}