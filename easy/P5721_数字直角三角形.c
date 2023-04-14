// Created by Glin on 2023/4/14.
#include "stdio.h"


int main(){
    int n;
    scanf("%d", &n);

    int output = 1;
    for (int row = 1; row <= n; ++row) {
        for (int i = 1; i <= n - row + 1; ++i) {
            printf("%02d", output);
            output ++;
        }
        printf("\n");
    }

    return 0;
}