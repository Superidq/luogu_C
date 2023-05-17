// Created by Glin on 2023/5/17.
#include "stdio.h"
#include "string.h"

char a[][5] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int main() {
    char str[201] = {'\0'};
    scanf("%[^\n]s", str);

    const int len_str = strlen(str);
    int count = 0;
    for (int i = 0; i < len_str; ++i) {
        if (str[i] == ' ')
            count++;
        else {
            if (str[i] >= 'a' && str[i] <= 'o')
                /* 全都是3个键，统一使用模的方式处理 */
                count += (str[i] - 'a') % 3 + 1;
            else if(str[i]>='p'&&str[i]<='s')
                count += str[i] - 'p' + 1;
            else if(str[i] >= 't' && str[i] <= 'v')
                count += str[i] - 't' + 1;
            else if(str[i] >= 'w' && str[i] <= 'z')
                count += str[i] - 'w' + 1;
        }
    }
    printf("%d", count);

    return 0;
}