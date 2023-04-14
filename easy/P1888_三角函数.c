//
// Created by Glin on 2023/4/14.
//
#include "stdio.h"


int getMaxComDivisor(int a, int b){
    int temp = 0;
    if(a < b){
        temp = a;
        a = b;
        b = temp;
    }
    while (a % b != 0){
        temp = b;
        b = a % b;
        a = temp;
    }
    return b;
}


int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    /* a b c从小到大排序，所以a是分子，b是分母 */
    int temp = 0;
    if(a > b){
        temp = a;
        a = b;
        b = temp;
    }
    if(a > c){
        temp = a;
        a = c;
        c = temp;
    }
    if(b > c){
        temp = b;
        b = c;
        c = temp;
    }

    int mcd = getMaxComDivisor(a, c);
    a /= mcd;
    c /= mcd;
    printf("%d/%d", a, c);

    return 0;
}