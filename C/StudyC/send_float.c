#include <stdio.h>
#include <string.h>

int main() {
    float data = 123.4f;  // 要复制的浮点数
    unsigned char TxData[4];      // 目标字节数组

    // 将 float 转换为字节数组
    memcpy(TxData, &data, sizeof(data));

    // 输出字节数组内容（以十六进制表示）
    for (int i = 0; i < sizeof(data); ++i) {
        printf("0x%02X ", TxData[i]);
    }
    printf("\n");

    return 0;
}
