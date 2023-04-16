// Created by Glin on 2023/4/16.
#include "stdio.h"
#include "stdbool.h"

/**
 * 判断未知数x是否处于area范围内
 * @param x 未知数x，代表处于数轴的位置
 * @param area 数组内保存各个区域的起始地址
 * @param n 区域数量，也是area数组元素数量的一半
 * @return 处于范围内则返回true，反之则返回false
 */
bool inArea(int x, int area[], int n){
    for (int i = 0; i < 2*n; i += 2) {
        if(x >= area[i] && x <= area[i+1])
            return true;
    }
    return false;
}

int main(){
    /* l表示马路长度 */
    int l_length = 0;
    /* n表示区域的数目 */
    int n = 0;
    scanf("%d %d", &l_length, &n);

    /* 初始化area，将各个区域的起始位置填入area */
    int area[2*n];
    for (int i = 0; i < 2 * n; ++i) {
        scanf("%d", &area[i]);
    }

    /* 施工前树的数量 */
    int const num_before = l_length + 1;
    /* 施工后树的数量 */
    int num_after = 0;
    /* 初始化所有数的状态，0为无树，1为有树 */
    int hasTree[num_before];
    for (int i = 0; i < num_before; ++i) {
        if(inArea(i, area, n))
            hasTree[i] = 0;
        else {
            hasTree[i] = 1;
            num_after ++;
        }
    }
    printf("%d", num_after);

    return 0;
}