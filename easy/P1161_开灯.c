// Created by Glin on 2023/5/13.
#include "stdio.h"
#include "stdbool.h"

int main(){
    int n = 0;
    scanf("%d", &n);

    /**
     * 初始状态都是关闭灯光，false状态
     * index与路灯编号对应关系为index+1=编号 */
    bool ON[2000000] = {0};
    while (n){
        double a = 0.0;
        int t = 0;
        scanf("%lf %d", &a, &t);
        int j = 0;
        for(int i = (int)a; i <= (int)t*a;){
            ON[i] = !ON[i];
            j ++;
            i = (int)(a + a*j);
        }
        n--;
    }
    for (int i = 0; i < 2000000; ++i) {
        if(ON[i]) {
            printf("%d", i);
            return 0;
        }
    }
    return 0;
}