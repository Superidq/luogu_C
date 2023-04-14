// Created by Glin on 2023/4/14.
#include "stdio.h"


int main(){
    int a_length = 0;
    scanf("%d", &a_length);
    int day = 1;
    while (a_length > 1){
        a_length = a_length / 2;
        day ++;
    }
    printf("%d", day);

    return 0;

}