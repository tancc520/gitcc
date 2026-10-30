#include <stdio.h>

int main() {
    int n;
    // 输入数字个数n
    scanf("%d", &n);
    int min, num;
    // 输入第一个数，并假设它是最小值
    scanf("%d", &min);
    for (int i = 1; i < n; i++) {
        // 依次输入后面的数
        scanf("%d", &num);
        // 如果当前数比min小，更新min
        if (num < min) {
            min = num;
        }
    }
    // 输出最小值
    printf("%d", min);
    return 0;
}