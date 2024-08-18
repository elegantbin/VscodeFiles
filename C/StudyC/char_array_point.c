#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_string1(void){
    char* s = "hello world!";
    return s;
}

char* get_string2(void){
    char* s = (char*)malloc(sizeof(char)*13);
    // *s = "hello world!";//错误写法，*s表示一个char类型的字符。后边 "hello world!"表示一个char*指针
    // *s = "hello world!";//错误写法，s原先分配了一块动态内存地址，然后又将 "hello world!"的地址赋给s,那么原先的malloc的地址就会丢失
    //正确写法
    strcpy(s, "hello world!");
    return s;
}

char* get_string3(void){
    static char s[] = "hello world!";//静态局部变量具有程序全生命周期，已初始化的存储在.data段
    return s;
}

//以下三种写法都是错误的，数组s[]为局部变量，函数调用结束后存储在栈上的局部变量就销毁了，会变成一个无效的内存指针，原来的数据没有了

// char* get_string4(void){
//     static char s[] = "hello world!";
//     return s;
// }

// char* get_string5(void){
//     char s[13] = "hello world!";
//     return s;
// }

// char* get_string6(void){
//const表示数组s中存储的数据不能改变是一个常量，但是const修饰的局部变量仍然存储在栈上
//     const char s[13] = "hello world!";
//     return s;
// }

int main(){
    char* s = NULL;
    s = get_string3();
    puts(s);
    return 0;
}