// Created by Glin on 2023/4/14.
#include "stdio.h"


int main(){
    int n = 0;
    scanf("%d", &n);
    int a;
    int min = 1000;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        if(min > a)
            min = a;
    }
    printf("%d", min);

    return 0;

}