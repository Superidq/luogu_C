//
// Created by Glin on 2023/3/29.
//
/**
 * M表示100位以内的数，用现有的数据类型一定会溢出，所以还是要用到大数运算
 * 不过这里用到的是大数运算的加法，我们立刻想到，大数运算是用an-1an-2...a2a1a0
 * 的数组来存储的，之前的大数运算我们使用的是1000进制，这里只有最多16进制，
 * 对大数进行运算有一个经典的步骤，即c表示进位值，如果数组元素k存的数大于进制数jinzhi_num，
 * 那么：循坏外设定c = 0; 循环内则有：result[k] = result[k] + a[k] + c;
 * c = result[k] / jinzhi_num; result[k] %= jinzhi_num;
 * 麻烦之处在于进制数到底是几，当jinzhi_num <= 10时，我们可以都用10进制或者10进制以上的数统一
 * 设定一个新进制，这样该新进制下可以直接发现是否为回文数；当jinzhi_num > 10后，
 * 额，从1000进制的角度来说，直接把数组头尾的元素存储的数拿出来比较，似乎也可以表示，
 * 只是在输入这个数的时候，十以上的数符号不一样，不过我们在计算时可以都直接用1000进制或者100进制，
 * 给它们的输入画分割线全都分开来，挨个塞进数组相应位置。我们知道，数组是按照
 * an-1an-2...a2a1a0这样来存的，所以也可以这样来读入！
 **/
#include "stdio.h"
#include "string.h"

#define N 105

char array_16[16] = "0123456789ABCDEF";


/* 核心函数。计算存在数组中的两数之和，这两个数互为额，倒过来的数，所以位数一样，结果存于input1[]中 */
void add_num(char input1[], int jinzhi_num){
    /* c表示进位值 */
    int c = 0;
    /* 先将char数组转化为int数组 */
    int int_input1[N] = {0};
    int int_input2[N] = {0};
    int len = strlen(input1);
    for(int i = 0; i < len; i++){
        if(input1[i] >= '0' && input1[i] <= '9'){
            int_input1[i] = input1[i] - '0';
            int_input2[len-i-1] = input1[i] - '0';
        } else{
            int_input1[i] = input1[i] - 'A' + 10;
            int_input2[len-i-1] = input1[i] - 'A' + 10;
        }
    }

    /* 需要解决例如：87+78 = 165，165比87多一位的问题
     * 这是10进制，多了一位，所以for中间的判定条件不能仅是k<len这种，
     * 而应该是加一个判定来让len也发生变化
     * */
    for(int k = 0; k < len; k++){
        int_input1[k] = int_input1[k] + int_input2[k] + c;
        /* 对存储数据数组的最高位进行判定，如果对它操作后使得其值需要进位，则再增加一个最高位 */
        if(int_input1[len-1] > jinzhi_num-1)
            len ++;
        c = int_input1[k] / jinzhi_num;
        int_input1[k] %= jinzhi_num;
    }

    /* 再将int数组转化为char数组 */
    int len1 = 0;
    /* 利用数字最高位一定不为0的性质来进行求解，此时的len1是倒着数，到第一次遇见非0位止，0的个数 */
    for(int i = N-1; int_input1[i]==0; i = N - len1 - 1){
        len1++;
    }

    /* 获得有效位数 */
    len1 = N - len1;
    for(int i = 0; i < len1; i ++){
        input1[i] = array_16[int_input1[i]];
    }
}


/* 将存放于数组中的数倒置，结果存放于result[]中，数组元素个数为num */
void reverse_num(char input[], char result[], int num){
    for(int i = 0; i < num; i++){
        result[i] = input[num-i-1];
    }
}


/* 检查存放于数组中的数是否为回文数，是则返回1，否则返回0 */
int is_num(char input[]){
    char tmp[N] = {'\0'};
    int len = strlen(input);
    reverse_num(input, tmp, len);
    for(int i = 0; i< len; i++){
        if(input[i]!=tmp[i])
            return 0;
    }
    return 1;
}


int main(){
    /* jinzhi_num表示进制 */
    int jinzhi_num = 0;
    int step = 0;

    char input_num[N] = {'\0'};
    scanf("%d", &jinzhi_num);

    char c;
    /* 在下次读取前清空缓冲区 */
    while((c=getchar())!='\n' && c!=EOF);

    scanf("%s", input_num);
//    getchar();

    int len = 0;

    if(is_num(input_num)){
        printf("STEP=0");
        return 0;
    }
    while (!is_num(input_num) && step<=30){
        step ++;
        len = strlen(input_num);
        char temp[N] = {'\0'};

        reverse_num(input_num, temp, len);
        add_num(input_num, jinzhi_num);

    }
    if (step <= 30){
        printf("STEP=%d", step);
    }else{
        printf("Impossible!");
    }

    return 0;

}
/** 看到的好方法，回头来看，自己的方法有些地方确实可以很精简的写出来，
 * 比如判断是否回文时可以不用reverse，直接遍历一半数组，前后对比即可
 * 并且好像并没有使用char数组来运算的必要？可以一开始就直接将其转换为int数组
 * 这样就不用每次循环就转换两次了
 **/

/*
#include <stdio.h>
#include <string.h>

#define MAXN 100

char s[MAXN + 1];
int a[MAXN + 1], b[MAXN + 1];

int main() {
    int n, len = 0, cnt = 0;
    scanf("%d%s", &n, s);
    len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            a[len - i] = s[i] - '0';
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            a[len - i] = s[i] - 'A' + 10;
        }
    }
    while (cnt <= 30) {
        int flag = 1;
        for (int i = 1; i <= len; i++) {
            b[i] = a[i] + a[len - i + 1];
        }
        for (int i = 1; i <= len; i++) {
            if (b[i] >= n) {
                b[i + 1] += b[i] / n;
                b[i] %= n;
                if (i == len) {
                    len++;
                }
            }
        }
        for (int i = 1; i <= len; i++) {
            if (b[i] != b[len - i + 1]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("STEP=%d\n", cnt+1);
            return 0;
        }
        cnt++;
        memcpy(a, b, sizeof(b));
    }
    printf("Impossible!\n");
    return 0;
}
 **/