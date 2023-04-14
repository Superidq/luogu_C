//
// Created by Glin on 2023/4/7.
//
#include "stdio.h"
#include "stdlib.h"

#define ROW 5


/** 要求输出共五行，星星数从上至下分别是1.3.5.3.1
 * 当然可以直接用printf函数输出，但是可以写一个通用函数
 *    *
 *   ***
 *  *****
 *   ***
 *    *
 * */
int main(){
    /* 用row表示目前第几行 */
    int row = 1;
    int blank;
    int num;

    while (row <= ROW){
        /* blank表示当前行的空格数 */
        blank = abs((ROW+1)/2 - row);
        /* num表示当前行的星号数 */
        num = ROW - blank * 2;

        /* 打印当前行空格 */
        while (blank > 0){
            printf(" ");
            blank --;
        }

        /* 打印当前行星号 */
        while (num > 0){
            printf("*");
            num --;
        }

        printf("\n");
        row ++;
    }

    return 0;
}