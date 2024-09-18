#include <stdio.h>

void determine_winner(long long a, long long b) {
    // 确保 a 是较大的数，b 是较小的数
    if (a < b) {
        long long temp = a;
        a = b;
        b = temp;
    }

    // 如果一堆是另一堆的两倍或更多
    if (a >= 2 * b) {
        printf("you\n");
        return;
    }
    
    // 如果不能直接决出胜负，根据当前剩余数量递归判断
    if ((a % b == 0) || (a / b > 1 && a % b != 0)) {
        printf("you\n");
        return;
    }
    else {
        printf("xiaoming\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        determine_winner(a, b);
    }
    return 0;
}
