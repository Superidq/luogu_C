//
// Created by Glin on 2023/4/7.
//
#include "stdio.h"
#include "stdlib.h"

#define ROW 10


/* 题目比上一题B2025还简单，但是这题不让ROW为5而为3，换个思路 */
int main(){
    int row = 1;
    int blank;
    int num;
    char c;

    scanf("%c", &c);

    while (row <= ROW){
        /** 不管怎么变，第几行从中间切一半，就有几个星号
         * 以ROW=4为例：
         *    *
         *   ***
         *  *****
         * *******
         * */
        blank = ROW - row;
        num = row * 2 - 1;

        while (blank > 0){
            printf(" ");
            blank --;
        }

        while (num > 0){
            printf("%c", c);
            num --;
        }

        printf("\n");
        row ++;
    }
    return 0;
}