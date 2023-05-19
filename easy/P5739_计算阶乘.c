// Created by Glin on 2023/5/18.
#include "stdio.h"

int main(){
    int n = 0;
    scanf("%d", &n);
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    printf("%d", result);

    return 0;
}