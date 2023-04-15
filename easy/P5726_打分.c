// Created by Glin on 2023/4/15.
#include "stdio.h"

int main(){
    int n;
    scanf("%d", &n);
    scanf("%*c");
    int max = 0;
    int min = 10;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
        if(min > a[i])
            min = a[i];
        if(max < a[i])
            max = a[i];
    }
    sum -= max + min;
    double result = 1.0 * sum / (n - 2);
    printf("%.2lf", result);

    return 0;
}