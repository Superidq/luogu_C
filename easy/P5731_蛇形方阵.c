// Created by Glin on 2023/5/14.
#include "stdio.h"

int main(){
    int n;
    scanf("%d", &n);
    int a[n][n];
    /**
     * 填充顺序：第0行、第n-1列（若存在）、第n-1行（若存在）、第0列、
     *         第1行（若存在）、第n-2列（若存在）、第n-2行（若存在）、第1列、
     *         ……
     *         第i行（若存在）、第n-1-i列（若存在）、第n-1-i行（若存在）、第i列
     * 每次填充n-1-i个 */
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = 0;
        }
    }

    int value = 1;
    if(n%2 == 1)
        a[(n+1)/2-1][(n+1)/2-1] = n*n;
    for (int row = 0; row <= n / 2; row++) {
        /**
         * 先填充第row行，
         * n为偶数时，填充个数为n-1、(n-2)-1、(n-2-2)-1直至最后一次列填充为n*n
         * n为奇数时，填充个数为n-1、(n-2)-1、...直至最终的首次行填充为n*n */
        int num = n-1-2*row;
        if(num <= 0)
            break;
        /* 循环内第一次行填充，列由对角线位置处填充相应次数 */
        for (int col = row; col < row+num; ++col) {
            a[row][col] = value;
            value ++;
        }
        /* 循环内第一次列填充，行由row处填充相应次数 */
        for (int i_row = row; i_row < row+num; ++i_row) {
            a[i_row][n-1-row] = value;
            value ++;
        }
        /* 循环内第二次行填充，列由对角线位置处填充相应次数 */
        for(int i_col = n-1-row; i_col > n-1-row-num; i_col--){
            a[n-1-row][i_col] = value;
            value ++;
        }
        /* 循环内第二次列填充，行由n-1-row处填充相应次数 */
        for(int i_row = n-1-row; i_row > n-1-row-num; i_row--){
            a[i_row][row] = value;
            value ++;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}