// Created by Glin on 2023/4/17.
#include "stdio.h"
#include "stdbool.h"

bool inArray(int a[], int element, int n){
    for (int i = 0; i < n; ++i) {
        if(a[i] == element)
            return true;
    }
    return false;
}

int main(){
    int n = 0;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
    }

    /* 排序 */
    int temp = 0;
    for (int i = 0; i < n - 1; i ++) {
        for (int j = i + 1; j < n; j ++) {
            if(a[j] < a[i]){
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }

    int cnt = 0;
    for (int i = n - 1; i > 1; i --) {
        /* 对每个a[i]查找 */
        for (int j = 0; j < i; j ++) {
            if(a[j] != a[i]-a[j] && inArray(a, a[i]-a[j], i)) {
                cnt++;
                break;
            }
        }
    }

    printf("%d", cnt);

    return 0;
}