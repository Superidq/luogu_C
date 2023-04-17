// Created by Glin on 2023/4/17.
#include "stdio.h"

/* 用an..a1a0表示一个数x */
void int2String(int x, int result[]){
    int i = 0;
    while (x){
        result[i] = x % 10;
        x /= 10;
        i ++;
    }
}

int main(){
    int min = 0;
    int max = 0;
    scanf("%d %d", &min, &max);

    /* 用数组存储从0~9各位出现的次数，其中下标index对应相关数字 */
    int a[10] = {0};
    for(int i = min; i <= max; i++){
        int string[11];
        for (int j = 0; j < 11; ++j) {
            string[j] = -1;
        }
        int2String(i, string);
        for (int j = 0; string[j] != -1; ++j) {
            a[string[j]] ++;
        }
    }

    for (int i = 0; i < 10; ++i) {
        printf("%d ", a[i]);
    }
    return 0;

}