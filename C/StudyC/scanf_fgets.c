#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char s[4];
    char t[4];
    printf("输入一个字符串t：\n");
    fgets(t, 4, stdin);//4包括了最后的结束标志，也就是最多输入3个字符。

    printf("输入一个字符串s：\n");
    scanf("%3s", s);//最多输入3个字符,不包括结束标志，但是会自动在字符串末尾添加一个标志符'\0'

    int slen = strlen(s);
    int tlen = strlen(t);

    printf("输出字符串t:%s\n", t);//如果空间够的话就会保留换行符'\n'//因此使用fgets输入字符串时，要注意是否要处理末尾的‘\n’
    // 检查最后一个字符是否是换行符
    // if (len > 0 && str[len - 1] == '\n') {
    //     str[len - 1] = '\0';  // 将换行符替换为字符串结束符
    // }

    printf("字符串t的长度:%d\n", tlen);
    printf("字符串t的最后一个字符:%d\n", t[tlen-1]);//'\n'ASCII值为10
    printf("输出字符串t结束标志：%d\n",t[tlen]);//'\0'ASCII值为0

    printf("输出字符串s:%s\n", s);//scanf输入不会保留换行符号
    printf("字符串s的长度:%d\n", slen);
    printf("输出字符串s结束标志：%d\n",s[slen]);

    return 0;
}