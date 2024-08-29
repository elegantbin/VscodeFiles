//合并两个非递减数组，合并后仍为非递减数据

#include <stdio.h>
#include <stdlib.h>

// 合并两个按非递减顺序排列的数组
int* mergeArrays(int* arr1, int arr1Len, int* arr2, int arr2Len, int* returnSize) {
    int* mergedArray = (int*)malloc((arr1Len + arr2Len) * sizeof(int));
    int i = 0, j = 0, k = 0;

    // 合并两个数组
    while (i < arr1Len && j < arr2Len) {
        if (arr1[i] <= arr2[j]) { // 因为是非递减顺序，所以小于等于号判断
            mergedArray[k++] = arr1[i++];
        } else {
            mergedArray[k++] = arr2[j++];
        }
    }

    // 如果 arr1 有剩余元素
    while (i < arr1Len) {
        mergedArray[k++] = arr1[i++];
    }

    // 如果 arr2 有剩余元素
    while (j < arr2Len) {
        mergedArray[k++] = arr2[j++];
    }

    *returnSize = arr1Len + arr2Len; // 合并后的数组大小
    return mergedArray;
}

int main() {
    int arr1Len, arr2Len;
    
    // 输入 arr1 的长度和元素
    printf("请输入 arr1 的长度: ");
    scanf("%d", &arr1Len);
    int* arr1 = (int*)malloc(arr1Len * sizeof(int));
    printf("请输入 arr1 的元素: ");
    for (int i = 0; i < arr1Len; i++) {
        scanf("%d", &arr1[i]);
    }
    
    // 输入 arr2 的长度和元素
    printf("请输入 arr2 的长度: ");
    scanf("%d", &arr2Len);
    int* arr2 = (int*)malloc(arr2Len * sizeof(int));
    printf("请输入 arr2 的元素: ");
    for (int i = 0; i < arr2Len; i++) {
        scanf("%d", &arr2[i]);
    }
    
    int returnSize;
    
    // 合并数组
    int* mergedArray = mergeArrays(arr1, arr1Len, arr2, arr2Len, &returnSize);

    // 输出合并后的数组
    printf("合并后的数组: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");

    // 释放动态内存
    free(arr1);
    free(arr2);
    free(mergedArray);

    return 0;
}