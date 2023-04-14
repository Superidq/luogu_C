#include <stdio.h>

// 测试中文乱码和一些小问题
int main() {
//    printf("Hello, World!\n"
//           "你好，世界！");
//    char c = 2 + '0';
//    printf("%c", c);
    int n;
    char str[30] = {'\0'};
    /* 丢弃第一个整数，将第二个存入变量n，由于第一个并非严格格式控制符故会读取失败 */
    scanf("%*d %d", &n);
    /* 依次读取，丢弃遇到的所有符合条件的，直至遇见第一个不符合条件的停止读取 */
    scanf("%*[a-z]");
    /* 继续读取缓冲区，直至遇到换行符，并将期间读取到的所有字符（包括空白符）存到str中 */
    scanf("%[^\n]", str);

    printf("n=%d, str=%s\n", n, str);

    return 0;
}
