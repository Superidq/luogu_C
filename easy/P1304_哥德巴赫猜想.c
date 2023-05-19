// Created by Glin on 2023/5/19.
#include "stdio.h"
#include "stdbool.h"

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
    int n = 0;
    scanf("%d", &n);

    for(int i = 4; i <= n; i += 2){
        printf("%d=", i);
        /* 10000内共有1229个质数 */
        int a1;
        for (a1 = 2; a1 < i; ++a1) {
            if(isPrime(i-a1) && isPrime(a1)) {
                printf("%d+%d\n", a1, i - a1);
                break;
            }
        }
    }

    return 0;
}