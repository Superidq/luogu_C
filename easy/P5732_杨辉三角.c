// Created by Glin on 2023/4/17.
#include "stdio.h"

int main(){
    int n = 0;
    scanf("%d", &n);
    int a[n][n];
    for(int row = 0; row < n; row ++){
        for(int col = 0; col <= row; col ++){
            if(row == 0 || col == 0 || col == row){
                a[row][col] = 1;
                printf("1 ");
            } else{
                a[row][col] = a[row-1][col] + a[row-1][col-1];
                printf("%d ", a[row][col]);
            }
        }
        printf("\n");
    }

    return 0;
}