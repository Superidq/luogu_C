// Created by Glin on 2023/5/14.
#include "stdio.h"
#include "string.h"

int main(){
    char s[101] = {'\0'};
    scanf("%s", s);
    for (int i = 0; i < strlen(s); ++i) {
        if(s[i] <= 'z' && s[i] >= 'a')
            s[i] -= 32;
    }

    printf("%s",s);

    return 0;
}