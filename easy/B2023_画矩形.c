// Created by Glin on 2023/4/16.
#include "stdio.h"

int main(){
    int a_y = 0;
    int b_x = 0;
    char c;
    int isAll = 0;
    scanf("%d %d %c %d", &a_y, &b_x, &c, &isAll);

    for (int i = 0; i < a_y; ++i) {
        for (int j = 0; j < b_x; ++j) {
            /* 外框始终实心 */
            if(i == 0 || i == a_y - 1){
                printf("%c", c);
            } else{
                /* 外框始终实心 */
                if(j == 0 || j == b_x - 1)
                    printf("%c", c);
                else{
                    /* 根据参数判断是否实心 */
                    if(isAll)
                        printf("%c", c);
                    else
                        printf(" ");
                }
            }
        }
        printf("\n");
    }

    return 0;
}