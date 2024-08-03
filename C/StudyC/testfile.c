#include <stdio.h>
#include <stdlib.h>

int main(){
    int a[5] = {0,1,2,3,4};
    //  (int*)((int*)a+1);
    printf("a是首元素地址:%p\n", a);
    printf("&a是数组的地址:%p\n", &a);
    printf("首元素地址+1:%p\n", a+1);
    printf("数组地址+1:%p\n", &a+1);
    printf("把数组地址强转成int类型的地址再+1:%p\n", (int*)&a + 1);
    printf("把数组地址强转成char类型的地址再+1:%p\n", (char*)&a + 1);
    printf("把数组地址强转成long类型的地址再+1:%p\n", (long*)&a + 1);
    printf("把数组地址强转成void类型的地址再+1:%p\n", (void*)&a + 1);

    // printf("size of char: %zu bytes\n", sizeof(char));
    // printf("size of int: %zu bytes\n", sizeof(int));
    // printf("size of long: %zu bytes\n", sizeof(long));
    // printf("size of long long: %zu bytes\n", sizeof(long long));
    // printf("size of 指针p: %zu bytes\n", sizeof(p));
    printf("size of 通用指针类型: %zu bytes\n", sizeof(void*));

    return 0;
}