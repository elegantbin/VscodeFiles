#include <stdio.h>
#include <stdlib.h>
// 小美有一个长度为 n 的数组 a1,a2,..,an，他可以对数组进行如下操作:
// 1.删除第一个元素 a1，同时数组的长度减一，花费为x。
// 2·删除整个数组，花费为 k*MEX(a)(其中MEX(a)表示 a 中未出现过的最小非负整数。例如[0,1,2,4]的MEX为3)。
// 小美想知道将 a数组全部清空的最小代价是多少，请你帮帮他吧。
// 输入描述:
// 每个测试文件均包含多组测试数据。第一行输入一个整数T(1 <= T <= 1000)代表数据组数，每组测试数据描述如
// 下第一行输入三个正整数n,k,x(l≤n≤2x10^5,1≤ k,x ≤10^9)n代表数组中的元素数量、删除整个数组的花费系数、删除单个元素的花费。
// 第二行输入 n 个整数a1,a2,·..,an(0 ≤ ai< n)，表示数组元素,除此之外，保证所有的 n之和不超过 2x10^5。
//示例：
// 输入：
//1
// 6 3 3
// 4 5 2 3 1 0
//输出：
// 15

int min(int a, int b) {
    return a < b ? a : b;
}

int find_mex(int *arr, int n) {
    int *flag = (int*)calloc(n + 1, sizeof(int));
    for (int i = 0; i < n; i++) {
        if (arr[i] < n) {
            flag[arr[i]] = 1;
        }
    }
    int mex = 0;
    while (flag[mex]) {
        mex++;
    }
    free(flag);
    return mex;
}

int main() {
    int T;
    scanf("%d", &T);
    int min_cost[1000];
    int out_T = T;

    while (T--) {
        int n, k, x;
        scanf("%d %d %d", &n, &k, &x);

        int *arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        min_cost[T] = k * find_mex(arr, n);  // 直接删除整个数组的成本

        // 动态更新 MEX 和最小成本
        for (int i = 1; i <= n; i++) {
            // 计算删除前 i 个元素的花费
            int curr_cost = i * x + k * find_mex(arr + i, n - i);
            min_cost[T] = min(min_cost[T], curr_cost);
        }

        free(arr);
    }
    while(out_T--){
        printf("%d\n", min_cost[out_T]);
    }

    return 0;
}
