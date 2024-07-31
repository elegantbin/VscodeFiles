
//给定一个数组，将数组中的各个数连在一起，使他们组成一个最大的数字

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 自定义比较函数，用于qsort排序
int compare(const void* a, const void* b) {
    char ab[20], ba[20];
    sprintf(ab, "%d%d", *(int*)a, *(int*)b);
    sprintf(ba, "%d%d", *(int*)b, *(int*)a);
    
    return strcmp(ba, ab); // 将ab和ba进行比较，降序排序
}

char* largestNumber(int* nums, int numsSize) {
    // 将nums按照自定义比较函数进行降序排序
    qsort(nums, numsSize, sizeof(int), compare);

    // 将排好序的nums拼接成一个字符串
    char* result = (char*)malloc(100 * sizeof(char));
    strcpy(result, "");
    for (int i = 0; i < numsSize; i++) {
        char temp[20];
        sprintf(temp, "%d", nums[i]);
        strcat(result, temp);
    }

    return result;
}

int main() {
    int nums1[] = {3, 30, 34, 5, 9};
    int numsSize1 = 5;
    char* result1 = largestNumber(nums1, numsSize1);
    printf("Output: %s\n", result1);
    free(result1);

    int nums2[] = {10, 2};
    int numsSize2 = 2;
    char* result2 = largestNumber(nums2, numsSize2);
    printf("Output: %s\n", result2);
    free(result2);

    return 0;
}