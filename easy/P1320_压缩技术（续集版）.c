// Created by Glin on 2023/4/18.
#include "stdio.h"
#include "string.h"

int changeClick(int click){
    if(click == 0)
        return 1;
    else
        return 0;
}

int main(){
    int zero = 0;
    int one = 0;
    char s[200] = {'\0'};

    int output = 0;
    int click = 0;
    int cnt = 0;
    while (scanf("%s", s)){
        scanf("%*c");
        int len = strlen(s);
        cnt += len;
        /* 第一次输出 */
        if(!output){
            printf("%d ", len);
            output ++;
        }
        for (int i = 0; i < len; ++i) {
            if(s[i] == '0' && click == 0)
                zero ++;
            else if(s[i] == '1' && click == 0){
                /* 遇到1 */
                click = changeClick(click);
                printf("%d ", zero);
                zero = 0;
            }
            if(s[i] == '1' && click == 1)
                one ++;
            else if(s[i] == '0' && click == 1){
                /* 遇到0 */
                click = changeClick(click);
                printf("%d ", one);
                one = 0;
                zero ++;
            }
        }
        if(zero != 0 && cnt == len*len) {
            printf("%d ", zero);
            break;
        }
        else if(one != 0 && cnt == len*len) {
            printf("%d ", one);
            break;
        }
    }

    return 0;
}