//
// Created by Glin on 2023/4/13.
//
#include "stdio.h"


int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int temp;
    /* a b c依次变大，先用a储存最小数 */
    if(a > b || a > c){
        if(b > c){
            /* a c互换 */
            temp = a;
            a = c;
            c = temp;
        } else{
            /* a b 互换 */
            temp = a;
            a = b;
            b = temp;
        }
    }
    if(b > c){
        temp = b;
        b = c;
        c = temp;
    }
    printf("%d %d %d", a, b, c);
    return 0;

}
