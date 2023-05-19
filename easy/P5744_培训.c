// Created by Glin on 2023/5/19.
#include "stdio.h"

struct student{
    char name[20];
    int age;
    int score;
};

int main(){
    int n_students = 0;
    scanf("%d", &n_students);
    struct student stu[n_students];
    for (int i = 0; i < n_students; ++i) {
        scanf("%s", stu[i].name);
        scanf("%d %d", &stu[i].age, &stu[i].score);
        stu[i].age ++;
        if(stu[i].score == 600)
            continue;
        else if(stu[i].score * 12 / 10 > 600)
            stu[i].score = 600;
        else
            stu[i].score = stu[i].score * 12 / 10;
    }
    for (int i = 0; i < n_students; ++i) {
        printf("%s %d %d\n", stu[i].name, stu[i].age, stu[i].score);
    }

    return 0;
}