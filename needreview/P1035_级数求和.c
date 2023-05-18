//
// Created by Glin on 2023/3/30.
//
#include "stdio.h"


int main(){
    double sum = 0.0;
    int k = 0;
    int n = 1;
    scanf("%d", &k);
    /* 此处若是在for循环条件上加入判定则会超时 */
    for (; ; n++) {
        sum += 1.0/n;
        if(sum > k*1.0)
            break;
    }
    printf("%d", n);
    return 0;
}
