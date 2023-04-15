// Created by Glin on 2023/4/15.
#include "stdio.h"

int main(){
    int yuSuan[12] = {0};
    int const EXTRA = 300;
    int bank = 0;

    for (int i = 0; i < 12; ++i) {
        scanf("%d", &yuSuan[i]);
    }

    int toMonth = 0;
    int lastMonth = 0;
    for (int i = 0; i < 12; ++i) {
        /* 这月余的钱 = 新给的工资+上个月余的-预算 */
        toMonth = EXTRA + lastMonth - yuSuan[i];
        if(toMonth >= 100){
            /* 进行存钱操作 */
            int temp = toMonth / 100;
            bank += temp * 100;
            toMonth -= temp * 100;
        } else if(toMonth < 0){
            /* 钱不够用 */
            printf("-%d", i+1);
            return 0;
        }
        lastMonth = toMonth;
    }
    /* 年末手里的钱 = 本月余的钱+银行本息 */
    toMonth += bank * 1.2;
    printf("%d", toMonth);

    return 0;
}