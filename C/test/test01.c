#include <stdio.h>

// 求两个数的最大公约数（gcd）
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 动态规划解决问题
int maxSumOfGcds(int arr[], int n, int k) {
    int dp[k+1][n+1];

    // 初始化dp数组
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    // 动态规划求解
    for (int i = 1; i <= k; i++) {  // 将序列分为i段
        for (int j = i; j <= n; j++) {  // 当前部分的终点
            int currentGcd = arr[j - 1];
            for (int l = j; l >= i; l--) {  // 从终点向左求gcd
                currentGcd = gcd(currentGcd, arr[l - 1]);
                dp[i][j] = (dp[i][j] > dp[i-1][l-1] + currentGcd) ? dp[i][j] : dp[i-1][l-1] + currentGcd;
            }
        }
    }

    return dp[k][n];
}

int main() {
    int n, k;
    
    // 读取输入
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 计算并输出最大得分
    printf("%d\n", maxSumOfGcds(arr, n, k));

    return 0;
}
