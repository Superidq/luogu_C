// Created by Glin on 2023/4/16.
#include "stdio.h"
#include "stdbool.h"

/**
 * 判断一个单元方块是否存在于被切割后的立方体中
 * @param x 单元方块x坐标
 * @param y 单元方块y坐标
 * @param z 单元方块z坐标
 * @param slicing 切割单元的对应坐标
 * @param n 一共切了多少次
 * @return 存在则返回true,不存在则返回false
 */
bool hasBlock(int x, int y, int z, int slicing[], int n){
    for (int i = 0; i < n * 6; i += 6) {
        if(x >= slicing[i] && x <= slicing[i+3]
        && y >= slicing[i+1] && y <= slicing[i+4]
        && z >= slicing[i+2] && z <= slicing[i+5])
            return false;
    }
    return true;
}

int main(){
    int x_length = 0;
    int y_width = 0;
    int z_height = 0;
    scanf("%d %d %d", &x_length, &y_width, &z_height);
    int n = 0;
    scanf("%d", &n);
    /* 储存切割位置坐标 */
    int slicing[n*6];
    for (int i = 0; i < n * 6; ++i) {
        scanf("%d", &slicing[i]);
    }

    /* 切割前方块数量 */
    int const num_before = x_length * y_width * z_height;
    /* 切割后方块数量 */
    int num_after = num_before;
    /* 三维的，所以要用三个循环遍历 */
    for (int x = 1; x <= x_length; ++x) {
        for (int y = 1; y <= y_width; ++y) {
            for (int z = 1; z <= z_height; ++z) {
                if(!hasBlock(x, y, z, slicing, n))
                    num_after --;
            }
        }
    }
    printf("%d", num_after);

    return 0;
}