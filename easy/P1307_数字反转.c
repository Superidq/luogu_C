// Created by Glin on 2023/4/15.
#include <stdlib.h>
#include "stdio.h"
#include "stdbool.h"

int main(){
    int n = 0;
    scanf("%d", &n);
    if(n == 0){
        printf("0");
        return 0;
    }
    if(n < 0) {
        n = abs(n);
        printf("-");
    }

    bool isZero = true;
    while (n){
        /* 从低往高，第一次遇到非零的再开始打印 */
        if(isZero){
            if(n % 10 == 0)
                n /= 10;
            if(n % 10 != 0)
                isZero = false;
        }
        if(!isZero) {
            printf("%d", n % 10);
        }
        n /= 10;
    }

    return 0;
}