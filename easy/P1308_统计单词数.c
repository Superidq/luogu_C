// Created by Glin on 2023/5/15.
/************************************************************************************
 * 做这道题的时候发现了一个自己没注意的不良编程习惯，就是滥用strlen()函数，这个函数其实就是遍历而已，
 * 所以相比来说还是比较耗时的，一次两次不算什么，每次需要用到表示字符串长度的时候都选他来跑一遍的话，
 * 时间极长，效率极低。因此需要对其进行优化，比如在一开始就用一个const int变量保存长度，这样每次调用其实是常量，
 * 或者是变量吧。。。这个问题以后再考察，但肯定比每次用到就跑一遍快的多的多得多，我在洛谷上没优化前直接超时了三个数据，
 * 优化后全都是3ms、4ms，最长的一个是300+ms，所以以后要注意这个。
 ************************************************************************************/
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"

/**
 * @brief 判断在str中的substring是否为一个完整的单词
 * @param str 句子
 * @param substring 单词
 * @param index 单词位置
 * @return
 */
bool isWholeWord(const char str[], const char substring[], const int index) {
    const int len_str = strlen(str);
    const int len_substring = strlen(substring);
    /* 分为三种情况：在句首、在句中、在句末 */
    if (index == 0 && (str[len_substring] == ' ' || str[len_substring] == '\0'))
        return true;
    else if (index == len_str - len_substring && str[index - 1] == ' ')
        return true;
    else if (str[index - 1] == ' ' && str[index + len_substring] == ' ')
        return true;
    return false;
}

/**
 * @brief 进行题目中要求的比较，即不区分大小写时一致，注意，本函数只比较单个字母
 * @param str 句子
 * @param substring 单词
 * @param index_in_str 句子中单词的索引
 * @param index_in_substring 单词自己的索引
 * @return
 */
bool isEqual(const char str[], const char substring[], const int index_in_str, const int index_in_substring) {
    if (str[index_in_str] == substring[index_in_substring] ||
        abs(str[index_in_str] - substring[index_in_substring]) == 'a' - 'A')
        return true;
    return false;
}

int main() {
    char substring[11] = {'\0'};
    char str[1000001] = {'\0'};
    scanf("%s", substring);
    /* 丢掉换行符 */
    scanf("%*c");
    scanf("%[^\n]s", str);

    int first_index = 0;
    bool index_change = false;
    int count = 0;
    const int len_str = strlen(str);
    const int len_substring = strlen(substring);
    if(len_str == len_substring){
        for (int i = 0; i < len_str; ++i) {
            if(!isEqual(str, substring, i,i)) {
                printf("-1");
                return 0;
            }
            else if(i == len_str-1){
                first_index = 0;
                count = 1;
                printf("%d %d", count, first_index);
                return 0;
            }
        }
    }
    for (int i = 0; i < len_str - len_substring; ++i) {
        if(isEqual(str,substring,i,0)){
            if(len_substring == 1){
                /* 那么直接判断其是否合法 */
                if(isWholeWord(str, substring, i)){
                    if(index_change)
                        count ++;
                    else{
                        first_index = i;
                        index_change = true;
                        count ++;
                    }
                }
            }
            for (int j = 1; j < len_substring; ++j) {
                if(!isEqual(str, substring, i+j, j))
                    break;
                else if(j == len_substring-1 && isEqual(str, substring, i+j, j)){
                    if(isWholeWord(str, substring, i)) {
                        if (index_change)
                            count++;
                        else {
                            first_index = i;
                            index_change = true;
                            count++;
                        }
                    }
                }
            }
        }
    }
    if(!index_change)
        printf("-1");
    else
        printf("%d %d", count, first_index);
    return 0;
}
