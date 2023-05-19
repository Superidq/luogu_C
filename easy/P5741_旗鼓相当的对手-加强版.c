// Created by Glin on 2023/5/19.
#include "stdio.h"
#include "stdlib.h"

struct student{
    char name[9];
    int Chinese_score;
    int Math_score;
    int English_score;
    int total_score;
};

int main(){
    int n = 0;
    scanf("%d", &n);
    struct student stu[n];
    for (int i = 0; i < n; ++i) {
        scanf("%s", stu[i].name);
        scanf("%d %d %d", &stu[i].Chinese_score, &stu[i].Math_score, &stu[i].English_score);
        stu[i].total_score = stu[i].Chinese_score + stu[i].Math_score + stu[i].English_score;
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i+1; j < n; ++j) {
            if(abs(stu[j].Chinese_score - stu[i].Chinese_score) <= 5
            && abs(stu[j].Math_score - stu[i].Math_score) <= 5
            && abs(stu[j].English_score - stu[i].English_score) <=5
            && abs(stu[j].total_score - stu[i].total_score) <= 10)
                printf("%s %s\n", stu[i].name, stu[j].name);
        }
    }
    return 0;
}