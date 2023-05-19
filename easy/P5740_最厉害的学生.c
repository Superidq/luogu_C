// Created by Glin on 2023/5/19.
#include "stdio.h"
#include "string.h"

int main(){
    int n_students = 0;
    scanf("%d", &n_students);
    int max_score[3] = {0};
    char max_str[9] = {'\0'};
    int max = -1;
    for (int i = 0; i < n_students; ++i) {
        char str[9] = {'\0'};
        scanf("%s", str);
        int s1, s2, s3;
        scanf("%d %d %d", &s1, &s2, &s3);
        if(max < s1+s2+s3){
            max = s1+s2+s3;
            max_score[0] = s1;
            max_score[1] = s2;
            max_score[2] = s3;
            strcpy(max_str, str);
        }
        scanf("*[^\n]");
    }
    printf("%s %d %d %d", max_str, max_score[0], max_score[1], max_score[2]);

    return 0;
}