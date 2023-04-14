//
// Created by Glin on 2023/4/7.
//
#include "stdio.h"
#include "math.h"


int main(){
    double a;
    double b;
    double c;
    scanf("%lf %lf %lf", &a, &b, &c);

    double p = (a+b+c)/2.0;
    double result = sqrt(p*(p-a)*(p-b)*(p-c));
    printf("%.1lf", result);

    return 0;
}