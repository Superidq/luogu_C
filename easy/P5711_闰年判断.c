//
// Created by Glin on 2023/4/7.
//
#include "stdio.h"


int main(){
    int n;
    scanf("%d", &n);

    if(n % 100 != 0 && n % 4 == 0){
        printf("1");
    } else if (n % 100 == 0 && n % 400 == 0){
        printf("1");
    } else
        printf("0");

    return 0;
}