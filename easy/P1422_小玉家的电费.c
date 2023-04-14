//
// Created by Glin on 2023/4/14.
//
#include "stdio.h"


int main(){
    int sum = 0;
    scanf("%d", &sum);

    double result = 0.0;
    if(sum > 400){
        sum -= 400;
        result += sum * 0.5663 + 150 * 0.4463 + 250 * 0.4663;
    } else if(sum > 150){
        sum -= 150;
        result += sum * 0.4663 + 150 * 0.4463;
    } else{
        result += sum * 0.4463;
    }
    printf("%.1lf", result);

    return 0;
}