// Created by Glin on 2023/4/15.
#include "stdio.h"

int main(){
    int n = 0;
    scanf("%d", &n);
    scanf("%*c");
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    /* 长度为1时特殊处理 */
    if(n == 1){
        printf("1\n");
        return 0;
    }
    int num = 0;
    int max = 0;
    for (int i = 1; i < n; ++i) {
        /* 如果跟上一个连上了 */
        if(a[i] - a[i-1] == 1){
            num ++;
            if(max < num)
                max = num;
        } else
            num = 0;
    }
    printf("%d\n", max + 1);

    return 0;

}