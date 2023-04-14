//
// Created by Glin on 2023/4/7.
//
#include "stdio.h"


int main(){
    int s;
    int v;
    scanf("%d %d", &s, &v);

    double tm_s = s / v + 10;
    int tm;
    if(s%v == 0){
        tm = (int)tm_s;
    } else{
        tm = (int)tm_s + 1;
    }
    int hour = tm / 60;
    int sec = tm % 60;
    /* c表示借位值 */
    int c = 0;
    if(sec > 0){
        c = 1;
        sec = 60 - sec;
    }
    hour = (8 - hour - c) % 24;
    if(hour < 0) hour += 24;

    printf("%02d:%02d", hour, sec);

    return 0;
}