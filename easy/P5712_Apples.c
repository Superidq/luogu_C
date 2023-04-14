//
// Created by Glin on 2023/4/7.
//
#include "stdio.h"


int main(){
    int x;
    scanf("%d", &x);

    if(x == 0 || x == 1){
        printf("Today, I ate %d apple.", x);
    } else{
        printf("Today, I ate %d apples.", x);
    }

    return 0;

}