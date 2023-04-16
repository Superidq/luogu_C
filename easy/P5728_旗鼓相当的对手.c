// Created by Glin on 2023/4/16.
#include <stdlib.h>
#include "stdio.h"

int main(){
    int N_students = 0;
    scanf("%d", &N_students);
    int const elements = N_students * 3;
    int score[elements];
    for (int i = 0; i < elements; ++i) {
        scanf("%d", &score[i]);
    }

    /* 整体思路大致类似冒泡排序，两个嵌套循环 */
    int cnt = 0;
    for (int i_stud = 0; i_stud < 3*N_students - 3; i_stud += 3) {
        for (int j_stud = i_stud + 3; j_stud < 3*N_students; j_stud += 3) {
            if(abs(score[i_stud] - score[j_stud]) <= 5
            && abs(score[i_stud+1] - score[j_stud+1]) <= 5
            && abs(score[i_stud+2] - score[j_stud+2]) <= 5
            && abs(score[i_stud]+score[i_stud+1]+score[i_stud+2] -
                score[j_stud]-score[j_stud+1]-score[j_stud+2]) <= 10)
                cnt ++;
        }
    }
    printf("%d", cnt);

    return 0;
}