//
// Created by Glin on 2023/4/3.
//
/**
 * 思路：首先想到需要将未知数项移到一边，其他所有数移到另一边，以等号为分界线
 * 另外，由于题目没有说出输入的整数范围，所以涉及到经典的大数精确运算，还记得
 * 是怎么实现的吗？数字通过数组a[]进行表示，an-1...a2a1a0来表示一个大数
 * 通过c表示进位，用len表示位数，循环外c=0；循环内：a[i]=a[i]+b[i]+c,
 * if(a[i]>jinzhi_num) len++; c = a[i]/jinzhi_num; a[i] %= jinzhi_num;
 * */
#include "stdio.h"
#include "string.h"

#define fN 2000
#define N 500


/*!
 * 对方程左右式进行操作，使得未知项在左式而其余项在右式
 * @param left_c
 * @param right_c
 * @param index 存储出现未知数项的位置
 * @param unknown
 */
void hebing_unknown(char left_c[], char right_c[], int index[], char unknown){
    int i = 0;
    for(; index[i] <= strlen(left_c); i++){

    }
    /* 先将右式中的未知数项移至左式 */

}


int main(){
    /* 用长度为fN的数组存储方程 */
    char fang_cheng[fN] = {'\0'};

    /* 左式和右式，未知数项放左，其他放右 */
    char left_c[fN] = {'\0'};
    char right_c[fN] = {'\0'};

    scanf("%s", fang_cheng);

    /* 左式运算集合（未知数项除外） */
    char left_temp[fN] = {'\0'};

    int len_fangcheng = 0;
    int len_left = 0;
    int len_right = 0;
    int flag = 0;
    char unknown = '0';
    /* index保存未知项出现在方程的位置 */
    int index[N] = {0};
    int i = 0;

    /* 获取左右式的值以及未知项用什么表示 */
    while (fang_cheng[len_fangcheng] != '\0'){
        if(fang_cheng[len_fangcheng] >= 'a' && fang_cheng[len_fangcheng] <= 'z'){
            index[i] = len_fangcheng;
            unknown = fang_cheng[len_fangcheng];
            i ++;
        }
        if(fang_cheng[len_fangcheng] != '=' && flag == 0){
            left_c[len_left] = fang_cheng[len_left];
            len_left ++;
        } else if(fang_cheng[len_fangcheng] == '='){
            flag = 1;
        }
        if(flag == 1){
            right_c[len_right] = fang_cheng[len_fangcheng];
            len_right ++;
        }
        len_fangcheng ++;
    }

    /* 合并同类未知项至左式 */
    hebing_unknown(left_c, right_c, index, unknown);

}