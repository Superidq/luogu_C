// Created by Glin on 2023/4/14.
#include "stdio.h"
#include "stdbool.h"

int hui[30000] = {0};

/* 平凡除法 or Eratoshenes筛法 */
bool isPrime(int n){
    if(n == 2)
        return true;
    for (int i = 2; i*i <= n; ++i) {
        if(n % i == 0)
            return false;
    }
    return true;
}

/**
 * 从两位数开始由小到大生成回文数，到七位数
 * @param Hui
 * @return 返回数组元素个数
 */
int generateHui(int Hui[]){
    /* 先生成二位回文数 */
    int i = 0;
    for(int d1 = 1; d1 <= 9; d1 += 2){
        Hui[i] = d1 + d1 * 10;
        i ++;
    }
    /* 生成三位回文数 */
    for(int d1 = 1; d1 <= 9; d1 += 2){
        for(int d2 = 0; d2 <= 9; d2 ++){
            Hui[i] = d1 + d2 * 10 + d1 * 100;
            i ++;
        }
    }
    /* 生成五位回文数 */
    for(int d1 = 1; d1 <= 9; d1 += 2){
        for(int d2 = 0; d2 <= 9; d2 ++){
            for(int d3 = 0; d3 <= 9; d3 ++){
                Hui[i] = d1 + d2 * 10 + d3 * 100 + d2 * 1000 + d1 * 10000;
                i ++;
            }
        }
    }
    /* 生成七位回文数 */
    for(int d1 = 1; d1 <= 9; d1 += 2){
        for(int d2 = 0; d2 <= 9; d2 ++){
            for(int d3 = 0; d3 <= 9; d3 ++){
                for(int d4 = 0; d4 <= 9; d4 ++){
                    Hui[i] = d1 + d2 * 10 + d3 * 100 + d4 * 1000
                            + d3 * 10000 + d2 * 100000 + d1 * 1000000;
                    i ++;
                }
            }
        }
    }
    return i;

}

int main(){
    int a_min = 0;
    int b_max = 0;
    scanf("%d %d", &a_min, &b_max);
    if(b_max == 100000000)
        b_max -= 1;

    int const len = generateHui(hui);
    /* 先打印10以内的未生成的回文质数 */
    for(int i = a_min; i <= b_max && i < 10; ++i){
        if(isPrime(i))
            printf("%d\n", i);
    }

    /* 再打印gen[]中符合要求的数 */
    for(int j = 0; hui[j] <= b_max && j < len; j ++){
        /* 注意范围之内 */
        if(hui[j] >= a_min && isPrime(hui[j]))
            printf("%d\n", hui[j]);
    }


    return 0;
}

//
///* 学习了大佬们的方法，位数为四位以上的偶数回文数必被11整除,但本方法依旧超时 */
//bool checkDigit(int n){
//    if((1000 <= n && n <= 9999) || (100000 <= n && n <= 999999) || n == 100000000)
//        return false;
//    return true;
//}
//
//bool isHui(int n){
//    if(n < 10)
//        return true;
//
//    /* 用an-1...a2a1a0来表示一个数 */
//    int a[9] = {0};
//    int i = 0;
//    while (n){
//        a[i] = n % 10;
//        n /= 10;
//        i ++;
//    }
//    /* 判断是否为回文，只有奇数参与进来，故去除中间位 */
//    for (int j = 0; j < i/2; ++j) {
//        if(a[j] != a[i-j-1])
//            return false;
//    }
//    return true;
//
//}
//
// /* 平凡除法 or Eratoshenes筛法 */
//bool isPrime(int n){
//    if(n == 2)
//        return true;
//    for (int i = 2; i*i <= n; ++i) {
//        if(n % i == 0)
//            return false;
//    }
//    return true;
//}
//
//int main(){
//    int a_min = 0;
//    int b_max = 0;
//    scanf("%d %d", &a_min, &b_max);
//
//    /* 绝对不能先找质数再判回文，一亿里有五百多万个质数，绝对超时
//     * 相应的，一亿里只有近两万个回文数 */
//    for (int i = a_min; i <= b_max; ++i) {
//        if(checkDigit(i) && isHui(i) && isPrime(i))
//            printf("%d\n", i);
//    }
//
//    return 0;
//}
