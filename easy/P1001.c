//
// Created by ligua on 2023/3/29.
//
#include "stdio.h"


int main(){
//    int int1 = 8;
//    short short1 = 8;
//
//    printf("int: %lu\n", sizeof(int));
//    printf("short: %ld\n", sizeof(short));
    long a;
    long b;
    long sum;
    scanf("%ld,%ld", &a, &b);

    sum = a + b;

    printf("%ld\n", sum);

    return 0;
}
