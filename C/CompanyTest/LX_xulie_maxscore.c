#include <stdio.h>
#include <stdlib.h>

//将一个数组分成几段，然后求每一段的gcd，最大公约数，然后求gcd总和的最大值
#define MIN_VALUE -10000

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    // 动态分配数组
    int* a = (int*)malloc(n * sizeof(int));
    int** dp = (int**)malloc((n + 1) * sizeof(int*));
    int** gcd_cache = (int**)malloc((n + 1) * sizeof(int*));
    
    for(int i = 0; i <= n; i++) {
        dp[i] = (int*)malloc((k + 1) * sizeof(int));
        gcd_cache[i] = (int*)malloc((n + 1) * sizeof(int));
    }

    // 输入数组
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // 初始化 dp 数组为极小值
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = MIN_VALUE;
        }
    }

    // 计算 gcd_cache
    for (int i = 0; i < n; i++) {
        int current_gcd = a[i];
        for (int j = i; j < n; j++) {
            current_gcd = gcd(current_gcd, a[j]);
            gcd_cache[i][j] = current_gcd;
        }
    }

    dp[0][0] = 0;  // 初始化dp的基准值

    // 动态规划求解
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int l = j; l <= i; l++) {
                dp[i][j] = max(dp[i][j], dp[l - 1][j - 1] + gcd_cache[l - 1][i - 1]);
            }
        }
    }

    // 输出结果
    printf("%d\n", dp[n][k]);

    // 释放动态分配的内存
    free(a);
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
        free(gcd_cache[i]);
    }
    free(dp);
    free(gcd_cache);

    return 0;
}