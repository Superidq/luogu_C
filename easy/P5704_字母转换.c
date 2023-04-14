//
// Created by Glin on 2023/4/7.
//
#include "stdio.h"


int main(){
    char c;
    scanf("%c", &c);

    c = c - 32;
    printf("%c", c);
//    printf("%d", 'a' - 'A');

    return 0;
}