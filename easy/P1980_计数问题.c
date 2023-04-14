// Created by Glin on 2023/4/14.
#include "stdio.h"


int main(){
    int n = 0;
    int x = 0;
    scanf("%d %d", &n, &x);
    int const N = n;

    int n_of_times = 0;
    for (int i = 1; i <= N; ++i) {
        /* 从最低位开始逐一审查 */
        int j = i;
        while (j > 0){
            /* 审查最低位 */
            if(j % 10 == x){
               n_of_times ++;
            }
            j /= 10;
        }
    }
    printf("%d", n_of_times);

    return 0;
}