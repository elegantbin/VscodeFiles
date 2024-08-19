// 编写一个程序，将用户输入的字符串进行处理，处理形式如下:
// "dddeeef"处理为"d3e3f4”(用户输入字符长度小于100)串

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* process_char_num(char* s){
    int len = strlen(s);
    char* str_num = (char*)malloc(sizeof(char)*(len+1));
    str_num[0] = '\0';
    int count = 0;
    int new_len = 0;
    int flag = 1;
    for(int i = 0; i <len; i++){
        count++;
        if(flag == 1){
            flag = 0;
            strncat(str_num, s+i, 1);
        }
        if(s[i+1] != s[i]){
            char temp[3];
            sprintf(temp, "%d", count);
            strcat(str_num, temp);
            count = 0;
            flag = 1;
        }
    }
    return str_num;
}


int main(){
    char s[100];
    printf("请输入一个长度小于100的字符串：\n");
    scanf("%100s", s);
    char* str_num = process_char_num(s);
    printf("%s\n", str_num);
    return 0;
}