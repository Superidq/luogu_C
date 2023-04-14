// Created by Glin on 2023/4/14.
#include "stdio.h"


/* 对数组由小到大进行排序 */
void bubbleSort(int a[], int n){
    int temp = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if(a[j] < a[i]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}


int main(){
    int a[3] = {0};
    char law[4] = {'\0'};
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%s", law);

    bubbleSort(a, 3);

    for (int i = 0; i < 3; ++i) {
        switch (law[i]) {
            case 'A':
                printf("%d", a[0]);
                break;
            case 'B':
                printf("%d", a[1]);
                break;
            case 'C':
                printf("%d", a[2]);
                break;
        }
        printf(" ");
    }

    return 0;
}