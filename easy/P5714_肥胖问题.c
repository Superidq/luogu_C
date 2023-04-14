//
// Created by Glin on 2023/4/7.
//
#include "stdio.h"


int main(){
    double m_weight;
    double h_height;

    scanf("%lf %lf", &m_weight, &h_height);
    double BMI = m_weight / (h_height * h_height);
    if(BMI < 18.5)
        printf("Underweight");
    else if(BMI < 24)
        printf("Normal");
    else{
        printf("%.4lf\n", BMI);
        printf("Overweight");
    }

    return 0;
}