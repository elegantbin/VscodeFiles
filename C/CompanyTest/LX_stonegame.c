
// 有两堆石子，开始时堆的大小分别为 
// a 和 b。每回合，玩家可以在石子数量较多的那一堆中取走一定倍数（不能为 0）的 
// min(a,b)。当某一方无法继续取走石子时，该方为输家。
// 现在你是先手，假设双方都采取最优决策，求你是否能获胜。
// 输入描述：
// 第一行是一个整数 t，表示测试样例的数量（1≤t≤10^5）。接下来有t 行，每行包含两个整数 
// a 和 b，表示开始时两堆石子的大小（1≤a,b≤10^18)
#include <stdio.h>
#include <stdbool.h>

bool solve(long long a, long long b) {
    if (a < b){
        long long temp = a;
        a = b;
        b = temp;
    }
    if (a % b == 0) return true;
    if (a / b > 1) return true;

    return !solve(b, a % b);
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        long long a, b;
        scanf("%d %d", &a, &b);

        if (solve(a, b)) printf("you\n");
        else printf("xiaoming\n");
    }

    return 0;
}