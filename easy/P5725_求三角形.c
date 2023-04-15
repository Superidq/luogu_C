// Created by Glin on 2023/4/15.
#include "stdio.h"

int main(){
    int n = 0;
    scanf("%d", &n);
    /* 打印正方形 */
    int out = 1;
    for(int row = 1; row <= n; row ++) {
        for (int col = 1; col <= n; col++) {
            printf("%02d", out);
            out ++;
        }
        printf("\n");
    }

    printf("\n");

    /* 打印三角形 */
    out = 1;
    for(int row = 1; row <= n; row ++) {
        for (int col = 1; col <= n; col++) {
            if(row + col <= n)
                printf("  ");
            else {
                printf("%02d", out);
                out ++;
            }
        }
        printf("\n");
    }
}