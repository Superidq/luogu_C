// Created by Glin on 2023/4/14.
#include "stdio.h"


int main(){
    int n, k = 0;
    scanf("%d %d", &n, &k);

    int A_sum = 0;
    int B_sum = 0;
    int A_amount = 0;
    int B_amount = 0;
    for (int i = 1; i <= n; ++i) {
        if(i % k == 0){
            A_sum += i;
            A_amount ++;
        } else{
            B_sum += i;
            B_amount ++;
        }
    }

    double A_average = 1.0 * A_sum / A_amount;
    double B_average = 1.0 * B_sum / B_amount;
    printf("%.1lf %.1lf", A_average, B_average);

    return 0;
}