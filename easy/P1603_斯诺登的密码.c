// Created by Glin on 2023/5/18.
/**
 * 本答案虽然可以AC，但是有一个问题，就是我自己测试的时候输入一些要输出0的测试点，会莫名其妙中断掉。。找了半天没发现为什么
 * */
#include "stdio.h"
#include "string.h"
#include "stdbool.h"

char official_num[][10] = {"one", "two", "three", "four", "five",
                           "six", "seven", "eight", "nine", "ten",
                           "eleven", "twelve", "thirteen", "fourteen",
                           "fifteen", "sixteen", "seventeen", "eighteen",
                           "nineteen", "twenty"};

int main() {
    char str[70] = {'\0'};
    scanf("%[^\n]s", str);
    int num[6] = {0};
    int num_index = 0;
    const int len_str = strlen(str);
    char substr[10] = {'\0'};
    for (int i = 0; i < len_str; ++i) {
        // TODO: to delete
//        if (i == 0)
//            printf("proceeding_提取并拷贝到num中\n");
//        if (i == len_str - 1)
//            printf("proceeding_提取 done\n");

        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            /* 拷贝单词 */
            for (int j = 0; str[i + j] != ' ' && str[i + j] != '.'; ++j) {
                substr[j] = str[i + j];
            }
            /* 保存数到num数组中 */
            for (int j = 0; j < 20; ++j) {
                // TODO: to delete
//                if (j == 0)
//                    printf("proceeding_子进程，比较并保存到num数组中\n");
//                if (j == 19)
//                    printf("proceeding_子进程 done\n");

                if (strcmp(substr, official_num[j]) == 0) {
                    num[num_index] = j + 1;
                    num_index++;
                    break;
                } else if (strcmp(substr, "a") == 0) {
                    num[num_index] = 1;
                    num_index++;
                    break;
                } else if (strcmp(substr, "both") == 0) {
                    num[num_index] = 2;
                    num_index++;
                    break;
                } else if (strcmp(substr, "another") == 0) {
                    num[num_index] = 1;
                    num_index++;
                    break;
                } else if (strcmp(substr, "first") == 0) {
                    num[num_index] = 1;
                    num_index++;
                    break;
                } else if (strcmp(substr, "second") == 0) {
                    num[num_index] = 2;
                    num_index++;
                    break;
                } else if (strcmp(substr, "third") == 0) {
                    num[num_index] = 3;
                    num_index++;
                    break;
                }
            }
            /* 将i调整到本单词结尾后一格 */
            const int len_substr = strlen(substr);
            i += len_substr;
            /* 重置substr */
            for (int j = 0; j < len_substr; ++j) {
                substr[j] = '\0';
            }
        }
    }
    for (int i = 0; i < 6; ++i) {
        // TODO: to delete
//        if (i == 0)
//            printf("proceeding_计算num取模中...\n");
//        else if (i == 5)
//            printf("proceeding_计算 done.\n");

        num[i] = (num[i] * num[i]) % 100;
    }
    /* 排序 */
    for (int i = 0; i < 5; ++i) {
        // TODO: to delete
//        if (i == 0)
//            printf("proceeding_排序中...\n");
//        if (i == 4)
//            printf("proceeding_排序 done.\n");

        for (int j = i + 1; j < 6; ++j) {
            if (num[i] > num[j]) {
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    bool is_first = true;
    for (int i = 0; i < 6; ++i) {
        // TODO: to delete
//        if (i == 0)
//            printf("输出中...\n");
//        if (i == 5)
//            printf("\n输出 done.\n");

        if (num[i] == 0)
            continue;
        else if (num[i] / 10 == 0) {
            if (is_first) {
                printf("%d", num[i]);
                is_first = false;
            } else {
                printf("%02d", num[i]);
            }
        } else {
            printf("%d", num[i]);
        }
    }
    if (is_first)
        printf("0");
    return 0;
}
// aas add edf f sd g过不了，离谱