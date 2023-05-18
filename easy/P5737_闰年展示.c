// Created by Glin on 2023/5/18.
#include "stdio.h"

int main(){
    int start = 0;
    int end = 0;
    scanf("%d %d", &start, &end);
    int num[end-start];
    int count = 0;
    for (int i = start; i <= end; ++i) {
        if(i%100!=0 && i%4==0) {
            num[count] = i;
            count++;
        }
        else if(i % 100 == 0 && i % 400 == 0) {
            num[count] = i;
            count++;
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < count; ++i) {
        printf("%d ", num[i]);
    }
    return 0;
}