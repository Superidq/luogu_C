// Created by Glin on 2023/4/17.
#include "stdio.h"

int changeClick(int click){
    if(click == 0)
        return 1;
    else
        return 0;
}

int main(){
    int yaSuoM[100] = {0};
    int size = 0;
    scanf("%d", &size);
    int temp = size * size;
    /* i表示压缩码数组的数量 */
    int i = 0;
    while (temp){
        scanf("%d", &yaSuoM[i]);
        temp -= yaSuoM[i];
        i ++;
    }
    /* 表示输出0还是1 */
    int click = 0;
    /* i表示压缩码数组的数量,temp表示本行剩余数量 */
    temp = size;
    int k = 0;
    while (k < i) {
        if(yaSuoM[k] <= temp){
            for (int j = 0; j < yaSuoM[k]; ++j) {
                printf("%d", click);
            }
            temp -= yaSuoM[k];
            /* 更换至下个状态 */
            click = changeClick(click);
            k ++;
        }
        /* 压缩码长度超过行剩余长度 */
        else if(yaSuoM[k] > temp && temp > 0){
            for (int j = 0; j < temp; ++j) {
                printf("%d", click);
            }
            /* 超过剩余长度时不更改状态，下一行继续本状态，因此i也无需更改 */
            /* 压缩码减去已打印的长度 */
            yaSuoM[k] -= temp;
            temp = 0;
        }
        if(temp == 0) {
            printf("\n");
            /* 重置剩余行长度 */
            temp = size;
        }
    }

    return 0;
}