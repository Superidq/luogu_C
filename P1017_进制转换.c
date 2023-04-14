//
// Created by Glin on 2023/3/30.
//
#include "stdio.h"
#include "stdlib.h"

#define N 50
char array_20[20] = "0123456789ABCDEFGHIJ";


int main(){
    int n;
    int jinzhi_num;
    scanf("%d %d", &n, &jinzhi_num);
    int nn = n;

    /* 用int数组进行处理，最后输出时通过array_20元素进行输出
     * 数组result[]按照an-1...a2a1a0的顺序来存储结果，所以
     * 元素位置索引刚好是基的次幂*/
    int result[N] = {0};
    int len = 0;
    /* 按照题目要求，负数基的余数同样需要是正数 */
    for(int i = 0; n!=0; i++){
        int yushu = n % jinzhi_num;
        if(yushu < 0){
            yushu +=  abs(jinzhi_num);
            result[i] = yushu;
            /* -17=-4*4+(-1) -17=-4*5+3 */
            n = (n - yushu) / jinzhi_num;
        } else{
            result[i] = yushu;
            n = n / jinzhi_num;
        }
        len ++;
    }

    /* 打印 */
    printf("%d=", nn);
    while (len){
        len --;
        printf("%c", array_20[result[len]]);
    }
    printf("(base%d)", jinzhi_num);
    return 0;

}

///* 此例说明当被除数为负数时，c语言的商取的余数也可能出现负数 */
//int main(){
//    printf("%d", (-17)%(-4));
//    return 0;
//}