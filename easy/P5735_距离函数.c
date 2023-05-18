// Created by Glin on 2023/5/18.
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main(){
    double x1, y1, x2, y2, x3, y3;
    scanf("%lf %lf", &x1, &y1);
    scanf("%lf %lf", &x2, &y2);
    scanf("%lf %lf", &x3, &y3);
    double s1 = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    double s2 = sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));
    double s3 = sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));
    printf("%.2lf", s1+s2+s3);

    return 0;
}