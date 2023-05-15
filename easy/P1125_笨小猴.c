// Created by Glin on 2023/5/14.
#include "stdio.h"
#include "stdbool.h"
#include "string.h"

bool isPrime(int n) {
    if(n < 2)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    char s[101] = {'\0'};
    int max_letter = 1;
    int min_letter = 1;
    scanf("%s", s);

    int count[26] = {0};
    for (int i = 0; i < strlen(s); ++i) {
        count[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; ++i) {
        if(count[i]){
            /* 将第一个字符出现次数赋给min和max */
            min_letter = count[i];
            max_letter = count[i];
            break;
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (count[i] > max_letter)
            max_letter = count[i];
        if (count[i] != 0 && count[i] < min_letter)
            min_letter = count[i];
    }
    if (isPrime(max_letter - min_letter))
        printf("Lucky Word\n%d", max_letter - min_letter);
    else
        printf("No Answer\n0");

    return 0;
}
