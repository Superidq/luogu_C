// Created by Glin on 2023/4/15.
#include "stdio.h"

int main(){
    int n = 0;
    scanf("%d", &n);
    int kawayi[n];
    int cnt[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &kawayi[i]);
        cnt[i] = 0;
        for (int j = 0; j < i; ++j) {
            if(kawayi[j] < kawayi[i])
                cnt[i] ++;
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", cnt[i]);
    }

    return 0;
}