//
// Created by Glin on 2023/4/7.
//
#include "stdio.h"

#define one_price 19


int main(){
    int a;
    int b;
    scanf("%d %d", &a, &b);

    int money = a * 10 + b;
    int num = money / one_price;

    printf("%d", num);

    return 0;
}