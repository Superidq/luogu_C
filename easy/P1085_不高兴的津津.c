//
// Created by Glin on 2023/4/13.
//
#include "stdio.h"


int notHappyDay(int plan[]){
    int i = 0;
    int max = 0;
    int index = 0;
    while (i < 14){
        if(plan[i] + plan[i+1] > 8 && max < (plan[i] + plan[i+1])){
                max = plan[i] + plan[i+1];
                index = i;
        }
        i += 2;
    }
    if(max != 0)
        return index/2 + 1;
    return 0;
}


int main(){
    int plan[14] = {0};
    int i = 0;
    while (i < 14){
        scanf("%d %d", &plan[i], &plan[i + 1]);
        i += 2;
    }

    printf("%d", notHappyDay(plan));
    return 0;
}