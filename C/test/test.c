#include <stdio.h>

int minOperationsToMultiple(int n, int x, int arr[]) {
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    // 如果总和已经是 x 的倍数，不需要任何操作
    if (totalSum % x == 0) {
        return 0;
    }

    int remainder = totalSum % x;
    int minOperations = n;  // 最少操作次数初始化为 n，即删除所有元素

    int prefixSum = 0;
    int found = 0;

    // 尝试从左边或者右边删除元素，寻找最短的子数组
    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        if (prefixSum % x == remainder) {
            minOperations = i + 1;
            found = 1;
        }
    }

    prefixSum = 0;
    for (int i = n - 1; i >= 0; i--) {
        prefixSum += arr[i];
        if (prefixSum % x == remainder) {
            minOperations = (n - i) < minOperations ? (n - i) : minOperations;
            found = 1;
        }
    }

    // 如果找到满足条件的子数组，返回操作数，否则返回 -1
    return found ? minOperations : -1;
}

int main() {
    int n, x;
    scanf("%d %d", &n, &x);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = minOperationsToMultiple(n, x, arr);
    printf("%d\n", result);

    return 0;
}
