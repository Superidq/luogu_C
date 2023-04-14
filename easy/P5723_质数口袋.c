// Created by Glin on 2023/4/14.
#include "stdio.h"
#include "stdbool.h"

/* 平凡除法 or Eratoshenes筛法 */
bool isPrime(int n){
    if(n == 1)
        return false;
    if(n == 2)
        return true;
    for (int i = 2; i*i <= n; ++i) {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main(){
    int L = 0;
    scanf("%d", &L);
    int amount = 0;
    int sum = 0;
    for (int i = 1; i <= L; ++i) {
        /* 先判是否为质数 */
        if(isPrime(i)){
            sum += i;
            /* 再判是否越界，不越界则输出 */
            if(sum <= L){
                printf("%d\n", i);
                amount ++;
            } else
                break;
        }
    }
    printf("%d", amount);

    return 0;
}