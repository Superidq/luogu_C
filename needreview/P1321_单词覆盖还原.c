// Created by Glin on 2023/5/17.
#include "stdio.h"
#include "string.h"

int main() {
    char str[256] = {'\0'};
    char boy[] = "boy";
    char girl[] = "girl";
    int boy_num = 0;
    int girl_num = 0;
    scanf("%s", str);

    const int len_str = strlen(str);
    for (int i = 0; i < len_str; ++i) {
        if ( (str[i-1] == '.' && (str[i] == boy[0] || str[i] == girl[0]))
        || (i == 0 && (str[i] == boy[0] || str[i] == girl[0])) ) {
            char substr[256] = {'\0'};
            int end_of_substr;
            /* 先copy子字符串 */
            if (((i>0 && str[i-1] == '.')||i==0 )&& (str[i] == boy[0] || str[i] == girl[0])) {
                for (end_of_substr = 0; str[end_of_substr + i] != '\0' && str[end_of_substr + i] != '.'; end_of_substr++) {
                    substr[end_of_substr] = str[end_of_substr + i];
                }
            }
            const int len_substr = strlen(substr);
            /* 当一个位置出现独有的字符串后便把属于该次粘贴的全部抠掉，以此来计算出现次数 */
            for (int j = 0; j < len_substr; ++j) {
                if (substr[j] == boy[0]) {
                    boy_num++;
                    /* 用x替换之 */
                    substr[j] = 'x';
                    /* 扣掉本次粘贴字符串（如有的话） */
                    if (substr[j + 1] == boy[1]) substr[j + 1] = 'x';
                    if (substr[j + 2] == boy[2]) substr[j + 2] = 'x';
                } else if (substr[j] == boy[1]) {
                    boy_num++;
                    substr[j] = 'x';
                    if (substr[j - 1] == boy[0]) substr[j - 1] = 'x';
                    if (substr[j + 1] == boy[2]) substr[j + 1] = 'x';
                } else if (substr[j] == boy[2]) {
                    boy_num++;
                    substr[j] = 'x';
                    if (substr[j - 2] == boy[0]) substr[j - 2] = 'x';
                    if (substr[j - 1] == boy[1]) substr[j - 1] = 'x';
                } else if (substr[j] == girl[0]) {
                    girl_num++;
                    substr[j] = 'x';
                    if (substr[j + 1] == girl[1]) substr[j + 1] = 'x';
                    if (substr[j + 2] == girl[2]) substr[j + 2] = 'x';
                    if (substr[j + 3] == girl[3]) substr[j + 3] = 'x';
                } else if (substr[j] == girl[1]) {
                    girl_num++;
                    substr[j] = 'x';
                    if (substr[j - 1] == girl[0]) substr[j - 1] = 'x';
                    if (substr[j + 1] == girl[2]) substr[j + 1] = 'x';
                    if (substr[j + 2] == girl[3]) substr[j + 2] = 'x';
                } else if (substr[j] == girl[2]) {
                    girl_num++;
                    substr[j] = 'x';
                    if (substr[j - 2] == girl[0]) substr[j - 2] = 'x';
                    if (substr[j - 1] == girl[1]) substr[j - 1] = 'x';
                    if (substr[j + 1] == girl[3]) substr[j + 1] = 'x';
                } else if (substr[j] == girl[3]) {
                    girl_num++;
                    substr[j] = 'x';
                    if (substr[j - 3] == girl[0]) substr[j - 3] = 'x';
                    if (substr[j - 2] == girl[1]) substr[j - 2] = 'x';
                    if (substr[j - 1] == girl[2]) substr[j - 1] = 'x';
                }
            }
            /* 将i调整到已算过的子字符串末尾索引以继续遍历其他子字符串 */
            i += end_of_substr;
        }
    }
    printf("%d\n%d", boy_num, girl_num);

    return 0;

}

/**
 * @brief 看过别人的答案之后无语了……竟然这么简单
 */
//int main()
//{
//    char ch[256];
//    int boy=0,girl=0;
//
//    scanf("%s",ch);
//    for(int i=0;i<strlen(ch);i++)
//    {
//        if(ch[i]=='b'||ch[i+1]=='o'||ch[i+2]=='y')
//            boy++;
//        if(ch[i]=='g'||ch[i+1]=='i'||ch[i+2]=='r'||ch[i+3]=='l')
//            girl++;
//    }
//    printf("%d\n%d",boy,girl);
//
//    return 0;
//}