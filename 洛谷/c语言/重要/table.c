#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 函数1：计算十进制数的字符长度（如 123→3，0→1）
int dec_len(int num) {
    if (num == 0) return 1; // 特殊处理0（避免长度为0）
    int len = 0;
    while (num > 0) {
        len++;
        num /= 10;
    }
    return len;
}

// 函数2：计算十六进制数的字符长度（含前导0x，如 15→4（0xF），31→4（0x1F））
int hex_len(int num) {
    if (num == 0) return 3; // 0的十六进制是0x0，长度3
    int len = 2; // 固定前导"0x"占2个字符
    while (num > 0) {
        len++;
        num /= 16;
    }
    return len;
}

// 函数3：将十进制数转换为十六进制字符串（含前导0x，大写字母）
void dec_to_hex(int num, char *hex_str) {
    char map[] = "0123456789ABCDEF";
    int i = 0;
    char temp[20]; // 临时存储反转后的十六进制字符（避免直接逆序）
    
    if (num == 0) {
        temp[i++] = '0'; // 0的十六进制是0
    } else {
        while (num > 0) {
            temp[i++] = map[num % 16]; // 取余得到当前位
            num /= 16;
        }
    }
    
    // 拼接前导0x + 反转temp得到正确顺序
    hex_str[0] = '0';
    hex_str[1] = 'x';
    int idx = 2;
    for (int j = i - 1; j >= 0; j--) {
        hex_str[idx++] = temp[j];
    }
    hex_str[idx] = '\0'; // 字符串结束符
}

int main() {
    char input[1000]; // 存储输入字符串（假设输入不超过1000字符）
    fgets(input, 1000, stdin); // 读取整行输入（含大括号、逗号）
    
    // 去除输入字符串中的换行符（fgets可能读取到\n）
    input[strcspn(input, "\n")] = '\0';
    
    char output[1000] = ""; // 存储输出结果
    strcat(output, "{"); // 输出开头的大括号
    
    // 解析输入：跳过开头{，提取每个数字（用逗号分隔）
    char *ptr = input + 1; // 指针从{后面开始
    while (*ptr != '}') { // 直到遇到结尾}停止
        // 提取当前数字（将逗号/}替换为\0，直接转换为整数）
        char *sep = strpbrk(ptr, ",}"); // 找到下一个逗号或}
        if (sep == NULL) break; // 格式正确，不会走到这
        *sep = '\0'; // 将逗号/}改为结束符，ptr指向的就是单个数字字符串
        
        int num = atoi(ptr); // 字符串转十进制整数
        
        // 计算两种表示的长度
        int d_len = dec_len(num);
        int h_len = hex_len(num);
        
        // 按规则选择输出格式
        if (h_len <= d_len) {
            // 十六进制更短，转换后拼接
            char hex_str[20];
            dec_to_hex(num, hex_str);
            strcat(output, hex_str);
        } else {
            // 十进制更短，直接拼接原数字字符串
            strcat(output, ptr);
        }
        
        // 处理分隔符：如果是逗号，拼接逗号；如果是}，不拼
        if (*(sep + 1) != '}') {
            strcat(output, ",");
        }
        
        ptr = sep + 1; // 指针移动到下一个数字开头
    }
    
    strcat(output, "}"); // 输出结尾的大括号
    printf("%s\n", output); // 打印结果
    
    return 0;
}