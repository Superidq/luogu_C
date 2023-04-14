//
// Created by ligua on 2023/3/29.
//
//#include "stdio.h"
//
//
//unsigned long jiecheng(unsigned long n){
//    unsigned long result = 1;
//    for(; n>=1; n--){
//        result *= n;
//    }
//    return result;
//
//}
//
//
//int main(){
//    int
//
//    /* 题目要求50范围，直接算一定会超时
//     * 考虑用移位运算：long类型是4字节*/
//
//    return 0;
//}
#include "stdio.h"

int main(int argc, char* argv[])
{
    double i,n,p;
    printf("n=?");
    scanf("%lf",&n);
    p=1.0;
    for (i=1;i<=n;i++)
        p*=i;
    printf("%lf!=%.16g/n",n,p);
    return 0;
}