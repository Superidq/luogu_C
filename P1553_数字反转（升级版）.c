// Created by Glin on 2023/5/18.
#include "stdio.h"
#include "stdbool.h"
#include "string.h"

/**
 * @brief 判断类型
 * @param str
 * @return 整数返回0，小数返回1，分数返回2，百分数返回3
 */
int getType(char str[]){
    const int len_str = strlen(str);
    for (int i = 0; i < len_str; ++i) {
        if(str[i] == '.')
            return 1;
        if(str[i] == '/')
            return 2;
        if(str[i] == '%')
            return 3;
    }
    return 0;
}

int main(){
    char str[22] = {'\0'};
    scanf("%s", str);
    if(getType(str) == 0){
        const int len_str = strlen(str);
        bool is_first = true;
        if(len_str == 1 && str[0] == '0')
            printf("0");
        else {
            for (int i = 0; i < len_str; ++i) {
                if (is_first && str[len_str - i - 1] == '0')
                    continue;
                printf("%c", str[len_str - i - 1]);
                if (is_first)
                    is_first = false;
            }
        }
    } else if(getType(str) == 1){
        /* 先打印整数 */
        int len_int = 0;
        for(; str[len_int] != '.'; len_int++) ;
        bool is_first = true;
        if(len_int == 1 && str[0] == '0')
            printf("0");
        else {
            for (int i = 0; i < len_int; ++i) {
                if (is_first && str[len_int - i - 1] == '0')
                    continue;
                printf("%c", str[len_int - i - 1]);
                if (is_first)
                    is_first = false;
            }
        }
        /* 再打印小数部分 */
        /* 首先打印小数点 */
        printf(".");
        /* len_int现在表示整数部分+小数点总长度 */
        len_int ++;
        int len_decimal = 0;
        int count_0 = 0;
        is_first = true;
        /* 本循环解决以下问题：获取小数部分总长度、获取第一个非零数前0的个数 */
        for(; str[len_decimal+len_int]!='\0'; len_decimal++) {
            if(is_first && str[len_decimal+len_int] == '0'){
                count_0 ++;
            } else if(is_first && str[len_decimal+len_int] != '0')
                is_first = false;
        }
        for (int i = 0; i < len_decimal-count_0; ++i) {
            printf("%c", str[len_int+len_decimal-i-1]);
        }
        if(count_0 == len_decimal)
            printf("0");
    } else if(getType(str) == 2){
        int len_molecular;
        for(len_molecular = 0; str[len_molecular]!='/'; len_molecular++) ;
        bool is_first = true;
        /* 考虑分子存在多个0的情况 */
        if(len_molecular == 1 && str[0] == '0')
            printf("0");
        else {
            for (int i = 0; i < len_molecular; ++i) {
                if (is_first && str[len_molecular - i - 1] == '0')
                    continue;
                printf("%c", str[len_molecular - i - 1]);
                if (is_first)
                    is_first = false;
            }
        }
        printf("/");
        is_first = true;
        len_molecular ++;
        int len_denominator;
        for(len_denominator = 0; str[len_molecular+len_denominator]!='\0'; len_denominator++) ;
        for (int i = 0; i < len_denominator; ++i) {
            if(is_first && str[len_molecular+len_denominator-i-1] == '0')
                continue;
            printf("%c", str[len_molecular+len_denominator-i-1]);
            if(is_first)
                is_first = false;
        }
    } else if(getType(str) == 3){
        int len_molecular;
        for(len_molecular = 0; str[len_molecular]!='%'; len_molecular ++) ;
        bool is_first = true;
        if(len_molecular == 1 && str[0] == '0')
            printf("0");
        else {
            for (int i = 0; i < len_molecular; ++i) {
                if (is_first && str[len_molecular - i - 1] == '0')
                    continue;
                printf("%c", str[len_molecular - i - 1]);
                if (is_first)
                    is_first = false;
            }
        }
        printf("%%");
    }
    return 0;
}