//
// Created by Glin on 2023/4/14.
//
#include "stdio.h"

/** 本思路的关键在于WEEK的理解，索引0~6对应星期i-1~星期i的时间跨度内是否工作，
 * 例如今天是星期五，对应索引为4，即4：周四00:00~周五00:00工作、
 *:5：周五00:00~周六00:00工作、6：周六00:00~周日00:00不工作、
 *:0：周日00:00~周一00:00不工作、1：周一00:00~周二00:00工作
 * */
int WEEK[7] = {0,1,1,1,1,1, 0};


int main(){
    int x_sday, n_sum = 0;
    scanf("%d %d", &x_sday, &n_sum);

    int result = 0;
    if(n_sum % 7 == 0){
        result += 250 * (n_sum / 7) * 5;
    } else{
        result += 250 * (n_sum / 7) * 5;
        for (int i = 1; i <= n_sum % 7; ++i) {
            /* x+i表示余出来的星期几，-1是为了和数组WEEK对齐 */
            /* x+i-1=3表示三~四工作 */
            result += 250 * WEEK[(x_sday+i-1) % 7];
        }
    }
    printf("%d", result);

    return 0;
}