//
// Created by Glin on 2023/4/7.
//
#include "stdio.h"


int main(){
    int x;
    scanf("%d", &x);

    x%2==0 && x>4 && x<=12 ? printf("1 ") : printf("0 ");
    !(x%2!=0 && !(x>4 && x<=12)) ? printf("1 ") : printf("0 ");
    (x%2==0 && !(x>4 && x<=12)) || (x%2!=0 && (x>4 && x<=12)) ? printf("1 ") : printf("0 ");
    x%2!=0 && !(x>4 && x<=12) ? printf("1 ") : printf("0 ");

    return 0;
}