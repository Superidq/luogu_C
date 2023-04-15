// Created by Glin on 2023/4/15.
#include "stdio.h"

int main(){
    /* INPUT & preHANDLE */
    int n;
    scanf("%d", &n);
    /* 清空缓冲区的换行符 */
    scanf("%*c");
    int a[n];
    int min = 1000;
    int max = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if(min > a[i])
            min = a[i];
        if(max < a[i])
            max = a[i];
    }

    printf("%d", max - min);
    return 0;

}