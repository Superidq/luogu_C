// Created by Glin on 2023/4/14.
#include <string.h>
#include "stdio.h"

void clean(char a[]){
    for (int i = 0; i < strlen(a); ++i) {
        if(a[i] == '-'){
            for (int j = i; j < strlen(a); ++j) {
                a[j] = a[j+1];
            }
        }
    }
}


int main(){
    char ISBN[14] = {'\0'};
    scanf("%s", ISBN);
    clean(ISBN);

    /* get int ISBN without '-' */
    int iISBN[10] = {0};
    for (int i = 0; i < 10; ++i) {
        if(ISBN[i] != 'X')
            iISBN[i] = ISBN[i] - '0';
        else
            iISBN[i] = 10;
    }

    /* get test */
    int test = 0;
    for (int i = 0; i < 9; ++i) {
        test += iISBN[i] * (i + 1);
    }
    test %= 11;

    if(test == iISBN[9])
        printf("Right");
    else{
        for (int i = 0; i < 9; ++i) {
            if(i == 1 || i == 4)
                printf("-%d", iISBN[i]);
            else
                printf("%d", iISBN[i]);
        }
        if(test < 10)
            printf("-%d", test);
        else
            printf("-X");
    }

    return 0;
}