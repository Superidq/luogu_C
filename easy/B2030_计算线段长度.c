// Created by Glin on 2023/4/16.
#include "stdio.h"
#include "math.h"

int main(){
    double xa, xb = 0;
    double ya, yb = 0;
    scanf("%lf %lf", &xa, &xb);
    scanf("%lf %lf", &ya, &yb);

    double s = sqrt((xa - ya) * (xa - ya) + (xb - yb) * (xb - yb));
    printf("%.3lf", s);

    return 0;
}