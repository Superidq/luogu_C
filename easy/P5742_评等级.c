// Created by Glin on 2023/5/19.
#include "stdio.h"
#include "stdbool.h"

struct student{
    int academic_score;
    int quality_development_score;
    bool isExcellent;
};

int main(){
    int n = 0;
    scanf("%d", &n);
    struct student stu[n];
    for (int i = 0; i < n; ++i) {
        /* id没用，直接丢掉 */
        scanf("%*d");
        scanf("%d %d", &stu[i].academic_score, &stu[i].quality_development_score);
        int temp = stu[i].academic_score*7 + stu[i].quality_development_score*3;
        if(temp >= 800 && stu[i].academic_score + stu[i].quality_development_score > 140)
            stu[i].isExcellent = true;
        else
            stu[i].isExcellent = false;
    }
    for (int i = 0; i < n; ++i) {
        if(stu[i].isExcellent)
            printf("Excellent\n");
        else
            printf("Not excellent\n");
    }

    return 0;
}