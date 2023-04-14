//
// Created by Glin on 2023/4/14.
//
#include "stdio.h"


int main(){
    int a[3];
    scanf("%d %d %d", &a[0], &a[1], &a[2]);

    if(a[0]<=0 || a[1]<=0 || a[2]<=0){
        printf("Not triangle\n");
        return 0;
    }

    /* 先对三边边长由小到大排序 */
    int temp = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = i+1; j < 3; ++j) {
            if(a[j]<a[i]){
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }

    /* 是否为三角形 */
    if(a[0]+a[1]<=a[2]){
        printf("Not triangle\n");
        return 0;
    }

    /* 是否为直角三角形 */
    if(a[0]*a[0] + a[1]*a[1] == a[2]*a[2]){
        printf("Right triangle\n");
    }
    /* 是否为锐角三角形 */
    else if(a[0]*a[0] + a[1]*a[1] > a[2]*a[2]){
        printf("Acute triangle\n");
    }
    /* 是否为钝角三角形 */
    else {
        printf("Obtuse triangle\n");
    }

    if(a[0] == a[1]) {
        printf("Isosceles triangle\n");
        if(a[1] == a[2])
            printf("Equilateral triangle\n");
    }

    return 0;
}