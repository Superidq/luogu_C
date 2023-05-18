// Created by Glin on 2023/5/18.
#include "stdio.h"
#include "stdbool.h"

bool isPrime(int n){
    if(n == 1)
        return false;
    if(n == 2)
        return true;
    for (int i = 2; i*i <= n; ++i) {
        if(n%i == 0)
            return false;
    }
    return true;
}

int main(){
    int count = 0;
    scanf("%d", &count);
    int a[count];
    for (int i = 0; i < count; ++i) {
        scanf("%d", &a[i]);
        if(!isPrime(a[i]))
            a[i] = -1;
    }
    for (int i = 0; i < count; ++i) {
        if(a[i] == -1)
            continue;
        printf("%d ", a[i]);
    }

    return 0;
}
