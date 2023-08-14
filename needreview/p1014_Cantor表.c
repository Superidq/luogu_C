//
// Created by ligua on 2023/8/14.
//
/*************************************************************************
 * 将该表看做一个矩阵，则Aij = i/j，主要是寻求N与坐标ij的关系。实际上，N处于[x, y]区间内，
 * 可通过累加确定，首先确定上确界y，即累加和首次不小于N的数为y，退而求其次找到x。设H为区间数，
 * 则H关系到x从什么方向上延伸到y。若H为偶数，则x斜向左下延伸到y，每次延伸i+1，y-1；
 * 若H为奇数，则x斜向右上延伸到y，每次延伸i-1, y+1
 * 那么，如何通过x y H获取i  j呢？我们很容易知道，H表示着左下角的i，右上角的j，故该区间要么
 * 是[H, 1] -> [1, H]，要么是[1, H] -> [H, 1]，是哪个则取决于H的奇偶性，H为奇则为
 * [H, 1] -> [1, H]，H为偶则为[1, H] -> [H, 1]，故而可确定具体位置。
 * INPUT: N OUTPUT: i j
**************************************************************************/
#include <stdio.h>

/**
 * 通过N获取N所在区间的上确界，下确界以及当前区间数，并保存于xyH数组
 * @param n
 * @param xyH
 */
void getCurrentInterval(int n, int xyH[3]){
    int i = 1;
    /* 上确界 */
    int supremum = i;
    int current_interval = 1;
    while (supremum < n){
        i ++;
        supremum += i;
        current_interval ++;
    }
    /* 下确界 */
    int infimum = supremum - i + 1;
    xyH[0] = infimum;
    xyH[1] = supremum;
    xyH[2] = current_interval;
}

int main(){
    int N;
    scanf("%d", &N);
    int answer[3] = {0};
    getCurrentInterval(N, answer);
    /* 输出结果为row, col */
    int row, col;
    if(answer[2] % 2 == 0){
        row = 1;
        col = answer[2];
        int temp = answer[0];
        row += N - temp;
        col = col - (N - temp);
    } else{
        row = answer[2];
        col = 1;
        int temp = answer[0];
        row = row - (N - temp);
        col += N - temp;
    }
    printf("%d/%d", row, col);
    return 0;
}