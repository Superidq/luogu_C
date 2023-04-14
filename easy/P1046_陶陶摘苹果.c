// Created by Glin on 2023/4/14.
#include "stdio.h"


int main(){
    int apple_heights[10] = {0};
    int h_height = 0;
    int bench_height = 30;

    scanf("%d %d %d %d %d %d %d %d %d %d",
          &apple_heights[0], &apple_heights[1], &apple_heights[2],
          &apple_heights[3], &apple_heights[4], &apple_heights[5],
          &apple_heights[6], &apple_heights[7], &apple_heights[8],
          &apple_heights[9]);
    scanf("%d", &h_height);

    h_height += bench_height;
    int get_apple = 0;
    for (int i = 0; i < 10; ++i) {
        if(apple_heights[i] <= h_height)
            get_apple ++;
    }
    printf("%d", get_apple);

    return 0;
}