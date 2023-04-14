//
// Created by Glin on 2023/4/7.
//
#include "stdio.h"


int main(){
    int h1;
    int s1;
    int h2;
    int s2;
    scanf("%d %d %d %d", &h1, &s1, &h2, &s2);

    /* c表示借位值 */
    int c = 0;
    int sec = (s2 - s1) % 60;
    if(sec < 0){
        c = 1;
        sec += 60;
    }
    int hour = h2 - h1 - c;
    printf("%d %d", hour, sec);
    return 0;
}