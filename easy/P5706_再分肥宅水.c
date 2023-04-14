//
// Created by Glin on 2023/4/7.
//
#include "stdio.h"


int main(){
    double t;
    int n;

    scanf("%lf %d", &t, &n);

    int result2 = n * 2;
    double result1 = t / n;
    /* printf函数的%.nlf指定小数位输出，本来就有四舍五入！ */
    printf("%.3lf\n", result1);

    /* 如果t=0，则输出n=0 */
    if(t == 0)
        printf("0");
    else
        printf("%d", result2);

    return 0;
}