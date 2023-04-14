//
// Created by Glin on 2023/4/13.
//
#include "stdio.h"
#include "stdbool.h"

const int MONTH[12] = {31, 28, 31, 30, 31, 30, 31,
                       31, 30, 31, 30, 31};


bool isRun(int year){
    if(year % 100 == 0 && year % 400 == 0){
        return true;
    } else if(year % 100 != 0 && year % 4 == 0){
        return true;
    }
    return false;
}


int main(){
    int year, month;
    scanf("%d %d", &year, &month);

    if(isRun(year) && month == 2){
        printf("29");
    } else{
        printf("%d", MONTH[month-1]);
    }
    return 0;
}