//
// Created by Glin on 2023/4/7.
//
#include "stdio.h"


int main(){
    int m_appleNum;
    int t_speed;
    int s_time;
    scanf("%d %d %d", &m_appleNum, &t_speed, &s_time);

    if(t_speed == 0){
        printf("0");
        return 0;
    }
    int eat_num = s_time / t_speed;
    if(eat_num >= m_appleNum){
        printf("0");
        return 0;
    }
    if(s_time % t_speed != 0){
        eat_num += 1;
    }
    printf("%d", m_appleNum - eat_num);

    return 0;
}
