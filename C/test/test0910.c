// 编写一个函数，把用户输入的二进制数转换为十进制数输出，
// 函数原型参考 std::string Convert(const std::string& input)

// 用例如下：
// 输入：01001
// 输出：9

// 输入：1234
// 输出： 非法输入，请输入二进制数

#include <stdio.h>
#include <string.h>
#include <math.h>

int convert(char* bi_num){
    int len = strlen(bi_num);
    int val = 0;
    for(int  i = 0; i < len ; i++){
        if(bi_num[i] == '1'){
            val += pow(2, len-1-i);
        }else if(bi_num[i] == '0'){
            continue;
        }else{
            val = -1;
            break;
        }
    }
    return val;
}

int main(){
    char s[32];
    printf("输入:");
    scanf("%32s", s);
    int val = convert(s);
    if(val == -1){
        printf("please input binary number\n");
    }else{
        printf("输出:%d\n", val);
    }
    return 0;
}