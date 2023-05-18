// Created by Glin on 2023/4/16.
#include "stdio.h"

/**
 * @brief 获得index对应彩票的中奖等级
 * @param index 表示购买的彩票索引，从0开始
 * @param myNumber 购买的彩票号码数组（已排序）
 * @param winNumber 公布的全奖号码（已排序）
 * @return 0~6分别对应特等奖~六等奖,7对应无奖项
 */
int getNumber(int index, int myNumber[], int winNumber[]){
    int award_level = 7;
    for (int i = 0; i < 7; ++i) {
        for (int j = index * 7; j < index * 7 + 7; ++j) {
            if(winNumber[i] == myNumber[j]) {
                /* 发现有一个号码之后，因无重复号码，故直接下一个号码循环 */
                award_level--;
                break;
            }
        }
    }
    return award_level;
}

/**
 * @brief 特制的由小到大的冒泡排序函数，只排序index对应的那一串号码
 * @param index 值为0时表示第一串，值为i时表示第i+1串
 * @param Number 待排序的数组
 */
void sortS(int index, int Number[]){
    int temp = 0;
    for (int i = index * 7; i < index * 7 + 6; ++i) {
        for (int j = i + 1; j < index * 7 + 7; ++j) {
            if(Number[j] < Number[i]){
                temp = Number[j];
                Number[j] = Number[i];
                Number[i] = temp;
            }
        }
    }
}

int main(){
    /* 彩票数量 */
    int n_buyCnt = 0;
    /* 中奖号码 */
    int winNumber[7] = {0};
    scanf("%d", &n_buyCnt);
    for (int i = 0; i < 7; ++i) {
        scanf("%d", &winNumber[i]);
    }
    /* 购买的彩票号码 */
    int myNumber[n_buyCnt*7];
    for (int i = 0; i < n_buyCnt * 7; ++i) {
        scanf("%d", &myNumber[i]);
    }

    /* 对中奖号码和已购号码两个数组进行特定排序 */
    sortS(0, winNumber);
    for (int i = 0; i < n_buyCnt; ++i) {
        sortS(i, myNumber);
    }

    /* 获取总的中奖情况，award数组索引0~6表示对应奖项，元素表示0~6对应奖项个数 */
    int award[7] = {0};
    for (int index = 0; index < n_buyCnt; ++index) {
        int gN = getNumber(index, myNumber, winNumber);
        if(gN < 7)
            award[gN] ++;
    }

    /* 输出 */
    for (int i = 0; i < 7; ++i) {
        printf("%d ", award[i]);
    }

    return 0;
}

/* 严格来说，我的算法时间复杂度是O(n)，翻题解时找到一个很不错的方法，利用了号码的取值范围[1.33]这个特性
 *
 * a[x]=1是将所有中奖数字作为数组下标，并且标记为1。当需要判断数字x是否是中奖数字时，
 * 只需要判断如果a[x]==1则是中奖数字，利用数组下标的性质使这部分算法时间复杂度为O(1)
 * */
//#include<stdio.h>
//int main()
//{
//    int a[34]={0},c[8]={0};//初始化也很重要
//    int n,i,j,t=0,p,q;     //n为彩票张数，t是计数器（上面一直说的）
//    scanf("%d",&n); //输入彩票张数
//    for(i=1;i<=7;i++)
//    {
//        scanf("%d",&p);//中奖号码
//        a[p]=1;//出现过的号码当作下标，把此下标的值赋值为1
//    }
//    for(i=1;i<=n;i++)
//    {
//        for(j=1;j<=7;j++)
//        {
//            scanf("%d",&q);//小明的号码
//            if(a[q]==1)
//                t++;
//        }
            // 这一步也很好，同样是利用了数组下标的特性，其实这一步跟我的差不多
//        c[7-t+1]++;
//        t=0;
//    }
//    for(i=1;i<=7;i++)
//    {
//        printf("%d ",c[i]);
//    }
//    return 0;
//}