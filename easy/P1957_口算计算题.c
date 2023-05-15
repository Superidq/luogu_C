// Created by Glin on 2023/5/15.
#include <stdlib.h>
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "math.h"

/**
 * @brief 要实现的是x的y次方
 * @param x int
 * @param y int
 * @return
 */
int myPow(int x, int y) {
    int temp = 1;
    /* 10^3=10*10*10 */
    while (y) {
        temp *= x;
        y--;
    }
    return temp;
}

int main() {
    int n;
    scanf("%d", &n);
    /* 2个最大4位数+2运算符+1个5位数+‘\0’=2*4+2+5+1=16 */
    char str[n][16];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 16; ++j) {
            str[i][j] = '\0';
        }
    }

    /* previous只存运算符，所以无需数组 */
    char previous;
    while (n) {
        /* 每次循环重置的变量 */
        bool undeclared = false;
        char current[5] = {'\0'};
        int x = 0;
        int y = 0;
        char operator;
        int result;
        /* 获取本行的第一个参数，可能是运算符，也可能是数 */
        scanf("%s", current);

        /* 未声明运算方式时，即已经在previous中存过之前的 */
        if (!(current[0] >= 'a' && current[0] <= 'c')) {
            undeclared = true;
            /* 先将current中存储的x算出来，然后在使其存储运算符进行统一运算 */
            for (int i = 0; i < strlen(current); ++i) {
                x += (current[i]-'0') * myPow(10, strlen(current)-1-i);
            }

            scanf("%d", &y);
            /* 获取真正的current[0] */
            current[0] = previous;
        }

        /* 存下本运算的运算符，留待后续使用 */
        previous = current[0];
        /* 由于未声明的处理方式中已获取x y，所以加一个判断
         * current只会是a~c，因为第一次时必为a~c */
        if (!undeclared) {
            scanf("%d %d", &x, &y);
        }
        if (current[0] == 'a') {
            operator = '+';
            result = x + y;
        } else if (current[0] == 'b') {
            operator = '-';
            result = x - y;
        } else {
            operator = '*';
            result = x * y;
        }
        int len = 0;
        if (x > 0)
            len += (int) log10(x) + 1;
        else
            len += 1;

        if (y > 0)
            len += (int) log10(y) + 1;
        else
            len += 1;

        if (result > 0)
            len += (int) log10(result) + 1;
        else if (result == 0)
            len += 1;
        else len += (int) log10(abs(result)) + 1 + 1;

        printf("%d%c%d=%d\n%d\n", x, operator, y, result, len+2);
        n--;
    }
}