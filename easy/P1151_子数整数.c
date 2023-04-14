//
// Created by Glin on 2023/3/30.
//
#include "stdio.h"


int main(){
    int k;
    scanf("%d", &k);

    int i = 10000;
    int flag = 0;
    while (i<=30000){
        int sub1;
        int sub2;
        int sub3;

        sub1 = i / 100;
        sub3 = i % 1000;
        sub2 = (i/10) % 1000;
        if(sub1%k ==0 && sub2%k == 0 && sub3%k == 0){
            printf("%d\n", i);
            flag = 1;
        }
        i++;
    }
    if(flag == 0)
        printf("No");

    return 0;
}