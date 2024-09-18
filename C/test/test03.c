#include <stdio.h>

int game(long long a, long long b) {
    if (a < b) {
        long long temp = a;
        a = b;
        b = temp;
    }
    
    // 如果 a/b >= 2，先手必赢，否则继续递归判断
    if (a / b >= 2) {
        return 1;  // 先手胜
    }
    
    // 递归进行游戏，交换 a 和 b，并继续操作
    if (a % b == 0) {
        return 0;  // 后手胜
    }
    
    return !game(b, a % b);
}

int main() {
    int t;  // 测试用例的数量
    scanf("%d", &t);
    
    while (t--) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        
        // 如果 game 返回 1，表示先手获胜；否则，后手获胜
        if (game(a, b)) {
            printf("you\n");
        } else {
            printf("xiaoming\n");
        }
    }
    
    return 0;
}
