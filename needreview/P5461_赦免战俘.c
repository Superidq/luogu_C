// Created by Glin on 2023/5/18.
#include "stdio.h"

#define MAX 1024

int a[MAX][MAX];

/**
 * @brief 通过递归对初始化后的矩阵进行赦免
 * @param len 矩阵边长
 * @param x 起始点横坐标，初始起始点设定为左上角（0,0）
 * @param y 起始点纵坐标
 */
void pardon(int len, int x, int y){
    /* 对递归设置最小情况并返回 */
    if(len == 2){
        a[y][x] = 0;
        return ;
    }
    /* 赦免左上角矩阵 */
    for (int row = y; row <= y + len / 2 - 1; ++row) {
        for (int col = x; col <= x + len / 2 - 1; ++col) {
            a[row][col] = 0;
        }
    }
    /* 赦免右上角矩阵 */
    pardon(len/2, x+len/2, y);
    pardon(len/2, x, y+len/2);
    pardon(len/2, x+len/2, y+len/2);

}
int main(){
    int n = 0;
    scanf("%d", &n);
    int nn = 1;
    for (int i = 0; i < n; ++i) {
        nn *= 2;
    }
    const int N = nn;
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            a[row][col] = 1;
        }
    }
    pardon(N, 0, 0);
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            printf("%d ", a[row][col]);
        }
        printf("\n");
    }

    return 0;
}