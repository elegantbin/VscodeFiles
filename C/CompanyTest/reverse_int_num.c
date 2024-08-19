// 要实现一个程序来反转32位有符号整数的数字部分，并处理溢出情况，你可以按照以下步骤编写 C 语言代码：

// 1. **读取输入**：获取需要反转的整数。
// 2. **处理负数**：如果整数为负数，将其处理为正数以进行反转，然后在结果中恢复负号。
// 3. **反转数字**：逐位提取数字并进行反转。
// 4. **检查溢出**：在反转过程中检查结果是否超出32位有符号整数的范围。
// 5. **输出结果**：打印反转后的结果或0（如果溢出）。

#include <stdio.h>
#include <limits.h>

int reverse(int x) {
    int reversed = 0;

    while (x != 0) {
        int digit = x % 10;
        x /= 10;

        // Check for overflow before it happens
        if (reversed > INT_MAX / 10 || reversed < INT_MIN / 10){
            return 0; // Return 0 in case of overflow
        }

        reversed = reversed * 10 + digit;
    }

    return reversed; // Restore the sign to the reversed number
}

int main() {
    int x;
    printf("Enter a 32-bit signed integer: ");
    scanf("%d", &x);

    int result = reverse(x);
    printf("Reversed integer: %d\n", result);

    return 0;
}