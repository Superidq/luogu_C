// Created by Glin on 2023/4/15.
#include "stdio.h"
#include "math.h"

int main(){
    int n = 0;
    double Fn = 0.0;
    scanf("%d", &n);
    Fn = (pow((1+ sqrt(5))/2, n) - pow((1- sqrt(5))/2, n))/ sqrt(5);
    printf("%.2lf", Fn);

    return 0;
}