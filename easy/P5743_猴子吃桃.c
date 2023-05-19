// Created by Glin on 2023/5/19.
#include "stdio.h"

int main(){
    int n = 0;
    int num_peach = 1;
    scanf("%d", &n);
    /* n代表第n天起床发现只有一个桃，则从第1天到第n-1天每天都在吃桃子 */
    for (int i = 0; i < n - 1; ++i) {
        num_peach = (num_peach+1)*2;
    }
    printf("%d", num_peach);

    return 0;
}