#include <stdio.h>
#include <ctype.h>

//将输入的字符串中的所有字母按字母顺序循环前移一位(即'a'变为''，'B'变为'A，以此类推)。
//输入为一个待处理的字符串str，1<=len(str)<=1000。字符串中只包含字母和空格。

void shiftString(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            if (str[i] == 'z') {
                str[i] = 'a';
            } else if (str[i] == 'Z') {
                str[i] = 'A';
            } else {
                str[i]++;
            }
        }
    }
}

int main() {
    char str[1001]; // 假设输入字符串的最大长度为1000
    printf("请输入字符串：");
    //字符串中有空格，所以不能使用scanf,scanf遇到空格就认为字符串结束了
    fgets(str, sizeof(str), stdin);

    // 处理字符串
    shiftString(str);

    // 输出处理后的字符串
    printf("处理后的字符串：%s\n", str);

    return 0;
}
