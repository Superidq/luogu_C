// Created by Glin on 2023/5/18.
#include "stdio.h"
#include "string.h"

int main(){
    char comet_name[7] = {'\0'};
    char group_name[7] = {'\0'};
    scanf("%s", comet_name);
    scanf("%s", group_name);
    int comet_number = 1;
    int group_number = 1;
    const int len_comet = strlen(comet_name);
    const int len_group = strlen(group_name);
    for (int i = 0; i < len_comet; ++i) {
        comet_number *= (comet_name[i] - 'A' + 1);
    }
    comet_number = comet_number % 47;
    for (int i = 0; i < len_group; ++i) {
        group_number *= (group_name[i] - 'A' + 1);
    }
    group_number = group_number % 47;
    if(comet_number == group_number)
        printf("GO");
    else
        printf("STAY");

    return 0;

}