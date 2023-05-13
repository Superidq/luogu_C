// Created by Glin on 2023/5/13.
//#include "stdio.h"
//
//void bubbleSort(int array[], int n){
//    int temp = 0;
//    for (int i = 0; i < n - 1; ++i) {
//        for (int j = i; j < n; ++j) {
//            if(array[i] > array[j]){
//                temp = array[i];
//                array[i] = array[j];
//                array[j] = temp;
//            }
//        }
//    }
//}
//
//int main(){
//    int s1 = 2;
//    int s2 = 2;
//    int s3 = 2;
//    scanf("%d %d %d", &s1, &s2, &s3);
//    int tmp = s1 * s2 * s3;
//
//    /* 将所有结果依次写入数组中 */
//    int result[tmp];
//    int index = 0;
//    for(int i = 1; i <= s1; i++){
//        for(int j = 1; j <= s2; j++){
//            for(int k = 1; k <= s3; k++){
//                result[index] = i + j + k;
//                index ++;
//            }
//        }
//    }
//    bubbleSort(result, index);
//
//    int times = 1;
//    int tmp_times = 1;
//    int answer = 0;
//    for (int i = 1; i < index; ++i) {
//        if(result[i] == result[i-1]){
//            tmp_times ++;
//        } else{
//            /* 即首先出现不同时，比较tmp与结果的大小 */
//            if(tmp_times > times){
//                times = tmp_times;
//                answer = result[i-1];
//            }
//            /* 只要出现不同，就重置tmp */
//            tmp_times = 1;
//        }
//    }
//
//    printf("%d", answer);
//    return 0;
//}

/**
 * 本题我的解法是相当暴力的，在查看题解时发现有前辈使用更好的算法解决。
 * 一个是使用了直接分析原理的方式，画图分析二维之后再讲到三维，很好，但这不是我用程序处理问题的思路，
 * 我的想法是计算机程序如果直接追求最省时的算法而不是贴近解决的问题的算法还同时不加注释说明，那么可维护性极差，
 * 不用换其他人，过段时间自己再看第二遍可能就看不懂了，所以如果追求时间最短要写清楚注释，那个特解方法暂时不表。
 * 先说说另一个比我好的算法使用的计数排序，特意找到了一篇博客介绍：
 * https://blog.csdn.net/lovely__RR/article/details/112867458
 * 可以发现，本题的场景还是较为适合该排序的，区间长度比较少。
 * 下面我再根据计数排序的思路写一遍。
 * */
#include "stdio.h"

int main() {
    int s1 = 2;
    int s2 = 2;
    int s3 = 2;

    scanf("%d %d %d", &s1, &s2, &s3);
    /**
     * counting数组用于记录[min, max]内每个数出现的次数 \n
     * 其index天然地带有与[min, max]中数的对应关系 \n
     * 且在本题中，min=3, max=s1+s2+s3 \n
     * 因此，该数组的index与三数之和的对应关系为：sum=index+3 */
    int counting[s1 + s2 + s3 - 3 + 1];
    for (int i = 0; i < s1 + s2 + s3 - 3 + 1; ++i) {
        /* 初始化 */
        counting[i] = 0;
    }

    for (int i = 1; i <= s1; ++i) {
        for (int j = 1; j <= s2; ++j) {
            for (int k = 1; k <= s3; ++k) {
                /* 在对应数的位置记录出现的次数 */
                counting[i + j + k - 3]++;
            }
        }
    }

    int max_time = 1;
    int index = 0;
    for (int i = 0; i < s1 + s2 + s3 - 3 + 1; ++i) {
        if (max_time < counting[i]) {
            max_time = counting[i];
            index = i;
        }
    }
    printf("%d", index + 3);

    return 0;

}