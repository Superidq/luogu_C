// Created by Glin on 2023/5/18.
#include "stdio.h"
#include "string.h"

int main(){
    int count[26] = {0};
//    int num_of_new_line = 0;
    char c;

    /* 这个读取方法全AC，下一个就全WA */
    while (scanf("%c", &c)!=EOF){
        if(c >= 'A' && c <= 'Z')
            count[c - 'A'] ++;
    }
//    while (num_of_new_line < 4){
//        char str[101] = {'\0'};
//        scanf("%[^\n]s", str);
//        num_of_new_line ++;
//        const int len_str = strlen(str);
//        for (int i = 0; i < len_str; ++i) {
//            if(str[i] >= 'A' && str[i] <= 'Z')
//                count[str[i] - 'A']++;
//        }
//    }
    /* 输出，字母在n+1行 */
    int max = 0;
    for (int i = 0; i < 26; ++i) {
        if(max < count[i])
            max = count[i];
    }
    /* 逐行打印 */
    int else_row = max;
    for (int row = 0; row < max; ++row) {
        for (int col = 0; col < 26; ++col) {
            if(count[col] < else_row)
                printf(" ");
            else{
                printf("*");
                count[col] --;
            }
            /* 在两个数之间打印空格 */
            if(col < 25)
                printf(" ");
        }
        else_row --;
        printf("\n");
    }
    printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");

    return 0;
}
/*
THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.
THIS IS AN EXAMPLE TO TEST FOR YOUR
HISTOGRAM PROGRAM.
HELLO!
 */