//
// Created by Glin on 2023/4/7.
//
#include "stdio.h"


int main(){
    int A;
    int B;
    int C;
    int score;
    scanf("%d %d %d", &A, &B, &C);

    score = (A*2 + B*3 + C*5) / 10;
    printf("%d", score);

    return 0;
}