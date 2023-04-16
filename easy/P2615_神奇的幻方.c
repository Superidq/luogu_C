// Created by Glin on 2023/4/16.
#include "stdio.h"

/**
 * @brief 根据给出的坐标将数填入一维数组N中，起到看起来是二维数组的效果
 * @param element 要填入元素的值
 * @param row 行坐标，从0开始
 * @param col 列坐标，从0开始
 * @param array 一维数组N
 * @param n 幻方大小，即边长
 */
void setElement(int element, int row, int col, int array[], int n){
    array[row * n + col] = element;
}

/**
 * @brief 返回其坐标，结果存储于result中，row=result[0], col=result[1]
 * @param element
 * @param result
 * @param array
 * @param n
 */
void findPosByElement(int element, int result[], int array[], int n){
    int i;
    for (i = 0; i < n * n; ++i) {
        if(array[i] == element){
            /* 获取行坐标 */
            result[0] = i / n;
            /* 获取列坐标 */
            result[1] = i % n;
            break;
        }
    }
}

/**
 * @brief 通过下标来寻找元素
 * @param element
 * @param row
 * @param col
 * @param array
 * @param n 幻方边长
 * @return 返回元素值
 */
int findElementByPos(int row, int col, int array[], int n){
    return array[row * n + col];
}

/**
 * @brief 打印幻方
 * @param array
 * @param n 幻方边长
 */
void output(int array[], int n){
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            printf("%d ", findElementByPos(row, col, array, n));
        }
        printf("\n");
    }
}

int main(){
    int N = 0;
    scanf("%d", &N);

    int a[N*N];
    /* C语言中变长数组不能直接初始化，只能循环赋值 */
    for (int i = 0; i < N*N; ++i) {
        a[i] = 0;
    }
    setElement(1, 0, N/2, a, N);
    int pos[2] = {0};
    for(int index = 1; index < N*N; index ++){
        /* index的row=result[0], col=result[1] */
        findPosByElement(index, pos, a, N);
        if(pos[0] == 0 && pos[1] != N-1)
            setElement(index+1, N-1, pos[1]+1, a, N);
        else if(pos[1] == N-1 && pos[0] != 0)
            setElement(index+1, pos[0]-1, 0, a, N);
        else if(pos[0] == 0 && pos[1] == N-1)
            setElement(index+1, pos[0]+1, pos[1], a, N);
        else if(findElementByPos(pos[0]-1, pos[1]+1, a, N) == 0)
            setElement(index+1, pos[0]-1, pos[1]+1, a, N);
        else
            setElement(index+1, pos[0]+1, pos[1], a, N);
    }
    output(a, N);

    return 0;

}