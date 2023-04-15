// Created by Glin on 2023/4/16.
#include "stdio.h"

int main(){
    int n = 0;
    scanf("%d", &n);
    int a[1000] = {n};
    int i = 0;
    while (a[i] != 1){
        i ++;
        if(a[i-1] % 2 == 0)
            a[i] = a[i-1] / 2;
        else
            a[i] = a[i-1] * 3 + 1;
    }
    for (int j = i; j >= 0; j--) {
        printf("%d ", a[j]);
    }
    return 0;
}