// Created by Glin on 2023/4/15.
#include "stdio.h"
#include "stdbool.h"

bool isRight(int k, int x, int n){
    if(3 * k + x == n && x <= 100 && x >= 1)
        return true;
    return false;
}

int main(){
    /* base尽可能大，add尽可能小，base<=100 */
    int x_base = 100;
    int k_add = 1;
    int n_sum = 0;
    int const WEEKS = 52;
    scanf("%d", &n_sum);

    /* 通过笔算推导，得出x+3*k=n/(7*WEEKS)，且有k>=MAX{(n`- 100)/3, 1} */
    n_sum = n_sum / (7 * WEEKS);
    /* 找到k最小值 */
    if((n_sum-100)/3 > 1) {
        if ((n_sum - 100) % 3 == 0)
            k_add = (n_sum - 100) / 3;
        else
            k_add = 1 + (n_sum - 100) / 3;
    }
    /* 计算该条件下对应的x */
    x_base = n_sum - 3 * k_add;
    /* 若超出范围则增加k */
    while (!isRight(k_add,x_base, n_sum)){
        k_add ++;
        x_base = n_sum - 3 * k_add;
    }
    printf("%d\n%d", x_base, k_add);

    return 0;
}