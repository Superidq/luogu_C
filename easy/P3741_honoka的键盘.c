// Created by Glin on 2023/5/17.
#include "stdio.h"
#include "stdbool.h"

const char LOVE[] = "VK";

int main(){
    int len_str = 0;
    char str[101] = {'\0'};
    bool flag[100] = {false};
    scanf("%d", &len_str);
    scanf("%s", str);

    int count = 0;
    /* 遍历第一遍找到已存在的LOVE */
    for (int i = 0; i < len_str; ++i) {
        if(str[i] == LOVE[0] && str[i+1] == LOVE[1] && !flag[i]) {
            count++;
            flag[i] = true;
            flag[i+1] = true;
        }
    }
    /* 遍历第二遍寻找做出更改的最佳位置 */
    for (int i = 0; i < len_str; ++i) {
        /* 首先要找到两个连续的可放LOVE的位置，且必须为VV、KK */
        if(!flag[i] && !flag[i+1] && str[i] == str[i+1]) {
            count++;
            flag[i] = true;
            flag[i + 1] = true;

            /* 只能更改一次 */
            break;
        }
    }
    printf("%d", count);

    return 0;
}