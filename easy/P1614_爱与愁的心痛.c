// Created by Glin on 2023/4/17.
#include "stdio.h"

int main(){
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int min = 0;
    int temp = 0;
    for (int i = 0; i < n - m + 1; ++i) {
        temp = 0;
        for (int j = 0; j < m; ++j) {
            if(i == 0){
                min += a[i+j];
            } else{
                temp += a[i+j];
            }
        }
        if(min > temp && i != 0)
            min = temp;
    }
    printf("%d", min);

    return 0;

}