//
// Created by Glin on 2023/4/7.
//
#include "stdio.h"


int main(){
    int n;
    scanf("%d", &n);

    int time_me = n * 5;
    int time_luogu = 11 + 3 * n;

    time_me<time_luogu ? printf("Local") : printf("Luogu");

    return 0;
}