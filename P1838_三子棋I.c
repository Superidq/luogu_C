//
// Created by Glin on 2023/3/30.
//
/**棋盘布局如下：
 * 1 2 3
 * 4 5 6
 * 7 8 9
 *
 * */
#include "stdio.h"


/* 判定胜负函数。所有连起来的胜利方的棋子都具有一定的特征，该特征为：
 * 设定三个决定胜的棋子为ABC，不分顺序
 * 则A通过方式1得到B后，B可以通过同样的方式1得到C，或者通过：
 * 方式2 = 两个逆序的方式1
 * 得到C
 */
void check(long input){
    /* ABABA，最快的胜利，即五位数时必为A胜 */
    if(input < 99999)
        printf("xiaoa wins.");
    /* ABABAB，六位数必为B胜 */
    else if(input < 999999)
        printf("uim wins.");
    /* ABABABA，七位数必为A胜 */
    else if(input < 9999999)
        printf("xiaoa wins.");
    /* 八位数必为B胜 */
    else if(input < 99999999)
        printf("uim wins.");
    /* 九位数则开始判定，先判断A胜，再判断平局，其中A 5个子，B 4个子 */
    else {
        int arrayA[5] = {0};
        int arrayB[4] = {0};
        int j = 0;
        int k = 0;
        for(int i = 0; i < 9; i++){
            if (i%2 == 0){
                arrayA[5 - j] = input % 10;
                input /= 10;
            } else{
                arrayB[4 - k] = input % 10;
                input /= 10;
            }
        }
        /* A必有子落在边上，因此从边上算起 */
        
    }
}


int main(){
    long input;
    scanf("%ld", &input);

    check(input);

    return 0;
}