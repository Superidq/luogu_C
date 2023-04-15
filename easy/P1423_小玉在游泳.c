// Created by Glin on 2023/4/15.
#include "stdio.h"

int main(){
    /* 目前走过总距离 */
    double sum = 0.0;
    /* 第一步走的距离 */
    double first_space = 2.0;
    /* 每一步相较上一步的距离 */
    double percent = 0.98;
    /* 已走的步数 */
    int amount = 0;
    double s_target = 0.0;

    scanf("%lf", &s_target);

    double temp_space = 0.0;
    while (sum < s_target){
        amount ++;
        if(amount == 1) {
            sum += first_space;
            temp_space = first_space;
        }
        else {
            /* 得到当前步对应的距离 */
            temp_space *= percent;
            sum += temp_space;
        }
    }
    printf("%d", amount);

    return 0;
}