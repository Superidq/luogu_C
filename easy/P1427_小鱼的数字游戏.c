// Created by Glin on 2023/4/16.
#include "stdio.h"

int main(){
    int a[100] = {0};
    int i = 0;
    scanf("%d", &a[i]);

    while (a[i] != 0){
        i ++;
        scanf("%d", &a[i]);
    }

    for (int j = i-1; j >= 0; j--) {
        printf("%d ", a[j]);
    }
    return 0;
}