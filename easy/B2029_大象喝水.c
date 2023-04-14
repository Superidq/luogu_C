//
// Created by Glin on 2023/4/7.
//
#include "stdio.h"
#include "math.h"

#define VOLUME 20000
#define pai 3.14


int main(){
    int h;
    int r;
    scanf("%d %d", &h, &r);

    double area = pai * r * r;
    double sum_f = VOLUME / area;

    int n = (int)ceil(sum_f / h);

    printf("%d", n);
    return 0;
}