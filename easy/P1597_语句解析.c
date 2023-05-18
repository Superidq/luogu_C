// Created by Glin on 2023/5/18.
#include "stdio.h"
#include "string.h"

int main(){
    char str[256] = {'\0'};
    scanf("%s", str);
    /* 用num数组来记录a b c三个数的值 */
    int num[3] = {0};
    char substr[6] = {'\0'};
    const int len_str = strlen(str);
    for (int i = 0; i < len_str; ++i) {
        if(str[i] >= 'a' && str[i] <= 'c'){
            if(str[i+3] >= '0' && str[i+3] <= '9'){
                /* 可以直接通过下标来记录a b c的值 */
                num[str[i] - 'a'] = str[i+3] - '0';
            } else if(str[i+3] >= 'a' && str[i+3] <= 'c'){
                /* 变量之间赋值亦然 */
                num[str[i] - 'a'] = num[str[i+3] - 'a'];
            }
        }
        i += 4;
    }
    /* 输出 */
    for (int i = 0; i < 3; ++i) {
        printf("%d ", num[i]);
    }

    return 0;
}