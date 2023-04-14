//
// Created by Glin on 2023/3/29.
//
/* 本程序依靠highPrecisionFactorial.c程序思路实现 */
/* 输入整数n，精确输出sigma(n!)
 * 数组a[]用于存放最终结果，数组元素a[k]用于存储3位整数，m为数组a[]实际存储位数
 * */
#include "stdio.h"

#define N 100 /* N可以依据Stirling公式预先估值 */


/* 输出函数。p1, p2, p3分别为a[j]的百位数、十位数、个位数 */
void output(int m, long a[N]){
    int k;
    int p1, p2, p3;

    for(k=m-1; k>=0; k--){
        /* 需要这三个参数是因为中间的数比如042必须挨个显示，不能省0 */
        p1 = a[k] / 100;
        p3 = a[k] % 10;
        p2 = a[k] / 10 % 10;

        if(k == m-1){
            if(p1 >= 1){
                printf("%d%d%d", p1, p2, p3);
            }
            else if(p2 >= 1){
                printf("%d%d", p2, p3);
            }
            else{
                printf("%d", p3);
            }
        }else{
            printf("%d%d%d", p1, p2, p3);
        }
    }
}


/* a[]用来存储结果，n则为需要计算阶乘的数 */
long* factotial(long a[], int n){
    /* c保存进位值 */
    int c;
    /* m 表示数组元素数*/
    int m = 1;

    a[0] = n;

    /* d是普通整数，a数组存储超高精度整数，下面循环进行a[k]与普通整数的乘法运算 */
    for(int d=n-1; d>=1; d--){
        c = 0;
        for(int k=0; k<m; k++){
            a[k] = a[k]*d + c;
            if(a[m-1] > 999)
                m++;
            c = a[k] / 1000;
            a[k] %= 1000;
        }
    }
    return a;
}


/* 输入一个数组，返回该数组倒着数，第几个元素第一次出现有效值 */
int getArrayNum(long a[]){
    int num = 0;
    int flag = 0;
    for(int i=N-1; i>=0; i--){
        num++;
        if(a[i] > 0){
            flag = 1;
            return num;
        }
    }
    return -1;
}


int main(){
    /* n用来保存输入的数 */
    int n;
    /* c保存进位值 */
    int c;
    /* result[]存储结果 */
    long result[N] = {0};
    /* m表示数组元素个数 */
    int m = 1;

    scanf("%d", &n);

    for(int d=n; d>=1; d--){
        c = 0;
        long tmp[N] = {0};

        /* 计算d的阶乘 */
        factotial(tmp, d);

        /* 计算tmp数组元素个数 */
        int m1 = N - getArrayNum(tmp) + 1;
        int m2 = N - getArrayNum(result) + 1;
        if(m1 > m2)
            m = m1;
        else
            m = m2;

        /* 计算阶乘和，将结果依次填入result[] */
        for(int k=0; k<m; k++){
            /* 计算阶乘和 */
            result[k] = result[k] + tmp[k] + c;

            c = result[k] / 1000;
            result[k] %= 1000;
        }
    }
    output(m, result);
    return 0;

}
