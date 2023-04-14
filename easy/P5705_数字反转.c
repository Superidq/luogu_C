//
// Created by Glin on 2023/4/7.
//
#include "stdio.h"
#include "string.h"


int main(){
    char str[7] = {'\0'};
    scanf("%s", str);

    int i = strlen(str) - 1;
    while (i >= 0){
        printf("%c", str[i]);
        i --;
    }

    return 0;
}