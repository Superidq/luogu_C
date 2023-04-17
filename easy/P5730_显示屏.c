// Created by Glin on 2023/4/17.
/* 每行中，每打印完一个数就打印一个点，再打印下一个数 */
#include "stdio.h"

/**
 * @brief 通过输入的行数和要输出的数字来打印该数字的部分
 * @param line 0~4
 * @param number 0~9
 */
void OutputByLine(int line, int number){
    if(line == 0){
        switch (number) {
            case 1:
                printf("..X");
                break;
            case 4:
                printf("X.X");
                break;
            default:
                printf("XXX");
                break;
        }
    } else if(line == 1){
        switch (number) {
            /* 0 4 8 9都相同 */
            case 1:
                printf("..X");
                break;
            case 2:
                printf("..X");
                break;
            case 3:
                printf("..X");
                break;
            case 5:
                printf("X..");
                break;
            case 6:
                printf("X..");
                break;
            case 7:
                printf("..X");
                break;
            default:
                printf("X.X");
                break;
        }
    } else if(line == 2){
        switch (number) {
            /* 2 3 4 5 6 8 9都是XXX */
            case 0:
                printf("X.X");
                break;
            case 1:
                printf("..X");
                break;
            case 7:
                printf("..X");
                break;
            default:
                printf("XXX");
                break;
        }
    } else if(line == 3){
        /* 1 3 4 5 7 9都是..X */
        switch (number) {
            case 0:
                printf("X.X");
                break;
            case 2:
                printf("X..");
                break;
            case 6:
                printf("X.X");
                break;
            case 8:
                printf("X.X");
                break;
            default:
                printf("..X");
                break;
        }
    } else if(line == 4){
        /* 0 2 3 5 6 8 9都是XXX */
        switch (number) {
            case 1:
                printf("..X");
                break;
            case 4:
                printf("..X");
                break;
            case 7:
                printf("..X");
                break;
            default:
                printf("XXX");
                break;
        }
    }
}

int main(){
    int n = 0;
    scanf("%d", &n);
    /* 本题出的有问题，翻了下讨论区发现，出题人输入的换行是CR+LF(\r\n)，所以要两次吃多余符 */
    scanf("%*c");
    scanf("%*c");
    char a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%c", &a[i]);
    }

    for (int line = 0; line < 5; ++line) {
        for (int i = 0; i < n; ++i) {
            /* 从0输出到n */
            OutputByLine(line, a[i]-'0');
            /* 不是最后一个数字时，输出.再输出下一个 */
            if(i != n-1)
                printf(".");
        }
        printf("\n");
    }
    return 0;
}