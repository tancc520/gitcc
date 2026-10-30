#include <stdio.h>

int main() {
    int n;
    // 读取正整数的个数
    scanf("%d", &n);
    int min, num;
    // 读取第一个数并初始化为最小值
    scanf("%d", &min);
    for (int i = 1; i < n; i++) {
        scanf("%d", &num);
        // 如果当前数比最小值小，更新最小值
        if (num < min) {
            min = num;
        }
    }
    // 输出最小值
    printf("%d\n", min);
    return 0;
}