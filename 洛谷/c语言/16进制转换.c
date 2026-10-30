#include <stdio.h>
#include <string.h>

// 十六进制字符转数字（0-9, A-F）
int hexToNum(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return 0; // 输入保证合法，此处防错
}

// 两位十六进制子串转十进制
int hex2dec(char *hex) {
    return hexToNum(hex[0]) * 16 + hexToNum(hex[1]);
}

// 十进制转两位十六进制字符串
void dec2hex(int dec, char *hex) {
    char map[] = "0123456789ABCDEF";
    hex[0] = map[dec / 16];
    hex[1] = map[dec % 16];
    hex[2] = '\0'; // C语言字符串必须以'\0'结尾，否则会乱码（标记字符串结束）
}

int main() {
    char color[8]; // 存储输入的#RRGGBB（长度7+1），还有'\0'则加一
    scanf("%s", color);
    
    // 解析R、G、B的十六进制子串
    char rHex[3], gHex[3], bHex[3];
    strncpy(rHex, color + 1, 2); rHex[2] = '\0';
    strncpy(gHex, color + 3, 2); gHex[2] = '\0';
    strncpy(bHex, color + 5, 2); bHex[2] = '\0';
    
    // 十六进制转十进制
    int r = hex2dec(rHex);
    int g = hex2dec(gHex);
    int b = hex2dec(bHex);
    
    // 计算反色的R、G、B
    int rInv = 255 - r;
    int gInv = 255 - g;
    int bInv = 255 - b;
    
    // 十进制转十六进制
    char rInvHex[3], gInvHex[3], bInvHex[3];
    dec2hex(rInv, rInvHex);
    dec2hex(gInv, gInvHex);
    dec2hex(bInv, bInvHex);
    
    // 输出反色的十六进制颜色码
    printf("#%s%s%s\n", rInvHex, gInvHex, bInvHex);
    
    return 0;
}