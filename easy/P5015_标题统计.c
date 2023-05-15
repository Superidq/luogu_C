// Created by Glin on 2023/5/15.
#include "stdio.h"

int main(){
    char c = ' ';
    char str[6] = {'\0'};
    int count = 0;

    scanf("%[^\n]s", str);
    for (int i = 0; str[i]!='\0'; ++i) {
        if(str[i]!=' ')
            count ++;
    }

    printf("%d", count);
    return 0;
}