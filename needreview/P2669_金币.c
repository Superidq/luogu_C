// Created by Glin on 2023/4/14.
/*************************************************************
 * i'天  '1' 2   '3' 4   5   '6' 7   8   9   '10'
 * k个   '1' 2   '2' 3   3   '3' 4   4   4   '4'
 * 设第'i'天有k个金币，其中，'i'刚好是右边界，因此到'i'天正有k个金币的边界，则：
 * 1+2+...+k = i， 即(1+k)*k/2=i，另外，'i'总是特定的离散的值，
 * 'i' = sigma(k), k ∈ N，因此，可以从小至大逐一寻找离所求天数
 * 最近的下界的'k'，并在该循环中 +=('k'*'k')来获得金币总数
 * **********************************************************/
#include "stdio.h"

/* 求和值，实为i的离散值集合的元素 */
int sigma(int k) {
    return (1+k)*k / 2;
}

/***
 * 计算最近下界
 * @param i_day
 * @param result [0]储存最近的下界k，[1]储存到下界k为止的金币总数
 */
void getINF(int i_day, int result[]) {
    int i = 1;
    int sum = 0;
    while (sigma(i) <= i_day){
        sum += i*i;
        i ++;
    }
    result[0] = i - 1;
    result[1] = sum;
}

int getIDayFromK(int k) {
    return sigma(k);
}

int main(){
    int k_days = 0;
    scanf("%d", &k_days);

    int result[2] = {0};

    /* 得到最近的下界k和对应的金币数 */
    getINF(k_days, result);
    /* 先求出下界k对应的'i'_day */
    int i_day = getIDayFromK(result[0]);
    /* 总金币数 = 囫囵的原result[1]+剩余天数*每天金币，
     * re[0]+1表示最后几天每天的金币 */
    result[1] += (k_days - i_day) * (result[0] + 1);

    printf("%d", result[1]);

    return 0;
}

/** 看到别人的写法，顿感惭愧，比我方法要简单的多，粘在这里学习一下 */
//int main()
int mmain()
{
    int k, sum=0, i, c=1;
    scanf("%d", &k);
    for(i = 1;i <= k;i ++){
        /* 这里很好，直接减去已计算的部分 */
        k -= i;
        sum += c * c;
        c ++;
    }
    printf("%d", sum + k * c);
    return 0;
}