#include <stdio.h>

int main() {
    int arr[3][6] = {   // 定义一个 3x6 的二维数组
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18}
    };

    int (*p)[6] = arr;  // p 是指向一个包含 6 个 int 元素的数组的指针

    printf("%p  %p\n", p, p+1);
    printf("%d\n", *(int*)(p+1));
    printf("%d\n", *(*(p+1)+1));
    // 使用 p 遍历二维数组
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }

    return 0;
}
