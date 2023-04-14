//
// Created by Glin on 2023/4/13.
//
#include "stdio.h"


int main(){
    int N = 0;
    int pencil[6] = {0};
    scanf("%d", &N);
    for (int i = 0; i < 6; i += 2) {
        scanf("%d %d", &pencil[i], &pencil[i+1]);
    }

    int money[3] = {0};
    /* 分别计算money */
    for (int i = 0; i < 3; ++i) {
        /* 刚好整除，正够用 */
        if(N % pencil[i*2] == 0){
            /* 单价*数量=费用 */
            money[i] = pencil[i*2+1] * (N / pencil[i*2]);
        } else{
            money[i] = pencil[i*2+1] * (N / pencil[i*2] + 1);
        }
    }

   /* 找到最小的money并输出 */
   if(money[0] <= money[1] && money[0] <= money[2])
       printf("%d", money[0]);
   else if(money[1] <= money[0] && money[1] <= money[2])
       printf("%d", money[1]);
   else
       printf("%d", money[2]);

    return 0;
}