// Created by Glin on 2023/5/15.
#include "stdio.h"
#include "string.h"
#include "stdbool.h"

/**
 * @brief 后插法插入字符串str到init末尾并输出
 * @param init 处理前的字符串
 * @param str 待插入的字符串
 */
void mode_1(char init[], char str[]) {
    int len = strlen(init);
    for (int i = 0; i < strlen(str); ++i) {
        init[len + i] = str[i];
    }
    printf("%s", init);
}

/**
 * @brief 截取字符串输出文档指定部分[start_index, start_index+num)
 * @param init 文档字符串
 * @param start_index 开始位置
 * @param num 输出长度
 */
void mode_2(char init[], int start_index, int num) {
    /* 初始化中间数组 */
    char temp[num+1];
    for (int i = 0; i < num + 1; ++i) {
        temp[i] = '\0';
    }
    /* 输出要求输出的 */
    for (int i = 0; i < num; ++i) {
        printf("%c", init[start_index + i]);
        temp[i] = init[start_index + i];
    }
    /* 删掉原数组其余部分 */
    int len_init = strlen(init);
    for (int i = 0; i < len_init; ++i) {
        if(i<num+1)
            init[i] = temp[i];
        else
            init[i] = '\0';
    }
}

/**
 * @brief 头插法插入字符串str到指定位置并输出
 * @param init 待处理文档字符串
 * @param str 待插入字符串
 * @param index 指定位置
 */
void mode_3(char init[], char str[], int index) {
    /* 防止init变化长度导致与预想不符，先定下其长度变量 */
    int len_init = strlen(init);
    /* init先腾位置，一共要移strlen(init)-index位 */
    for (int i = 0; i < len_init - index; i++) {
        /* 倒着腾位置，从后向前，每个腾strlen(str)长度 */
        init[len_init - i + strlen(str) - 1] = init[len_init - i - 1];
    }
    for (int i = 0; i < strlen(str); ++i) {
        init[index+i] = str[i];
    }
    /* 输出 */
    printf("%s", init);
}

/**
 * @brief 查找字符串str在文档中最先出现的位置并输出，找不到输出-1
 * @param init 文档字符串
 * @param str 待查找字符串
 */
void mode_4(char init[], char str[]){
    int len_init = strlen(init);
    bool find_it = false;
    int index = 0;

    for (int i = 0; i < len_init; ++i) {
        if(init[i] == str[0] && strlen(str)>1){
            for (int j = 1; j < strlen(str); ++j) {
                if(init[i + j] != str[j])
                    /* 直接跳出当前for循环 */
                    break;
                else if(j == strlen(str)-1 && init[i+j] == str[j]){
                    find_it = true;
                    index = i;
                }
            }
        }else if(init[i] == str[0] && strlen(str)==1){
            find_it = true;
            index = i;
        }
        if(find_it)
            break;
    }
    if(find_it)
        printf("%d", index);
    else
        printf("-1");
}

int main() {
    int n;
    char init_str[1000] = {'\0'};
    scanf("%d", &n);
    scanf("%s", init_str);
    while (n) {
        int mode;
        char str[101] = {'\0'};
        int start_index;
        int num;
        scanf("%d", &mode);
        switch (mode) {
            case 1:
                scanf("%s", str);
                mode_1(init_str, str);
                printf("\n");
                break;
            case 2:
                scanf("%d %d", &start_index, &num);
                mode_2(init_str, start_index, num);
                printf("\n");
                break;
            case 3:
                scanf("%d %s", &start_index, str);
                mode_3(init_str, str, start_index);
                printf("\n");
                break;
            case 4:
                scanf("%s", str);
                mode_4(init_str, str);
                printf("\n");
                break;
            default:
                break;
        }

        n--;
    }
}