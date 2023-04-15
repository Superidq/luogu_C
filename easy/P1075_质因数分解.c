// Created by Glin on 2023/4/15.
#include "stdio.h"
#include "math.h"

int main(){
    int n = 0;
    scanf("%d", &n);
    if(n == 2 || n == 1){
        printf("%d", n);
    }
    /* 不能先找该范围的质数再判断，因为一亿里面有五百多万个质数，会超时
     * 输入的n不是任意的，而是质数之积，因此只有一对解 */
    for(int i = 2; i <= sqrt(n); i ++){
        if(n % i == 0){
            printf("%d", n / i);
            return 0;
        }
    }
    return 0;
}