#include <stdio.h>
#include <limits.h>

// 获取最大公约数函数
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // 初始化dp数组
    int dp[n+1][k+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = (j == 0) ? 0 : INT_MIN;
        }
    }
    
    // 遍历所有可能的划分
    for (int j = 1; j <= k; j++) {
        for (int i = 1; i <= n; i++) {
            int current_gcd = 0;
            for (int p = i; p >= 1; p--) {
                current_gcd = gcd(current_gcd, a[p-1]);
                dp[i][j] = max(dp[i][j], dp[p-1][j-1] + current_gcd);
            }
        }
    }

    printf("%d\n", dp[n][k]);
    
    return 0;
}
