#include <stdio.h> 

void balance(int p[], int n) {
    int is_balanced = 0; // 标记是否找到平衡点
    for (int i = 0; i < n - 1; i++) { // i 是左侧最后一个元素的索引（分割点在 i 和 i+1 之间）
        int sum_left = 0;
        int sum_right = 0;
        // 计算左侧和：[0, i]（前 i+1 个元素）
        for (int j = 0; j <= i; j++) {
            sum_left += p[j];
        }
        // 计算右侧和：[i+1, n-1]（剩余元素）
        for (int j = i + 1; j < n; j++) {
            sum_right += p[j];
        }
        if (sum_left == sum_right) {
            is_balanced = 1;
            break; // 找到后立即退出循环
        }
    }
    // 最终只输出一次结果
    printf("%s\n", is_balanced ? "Yes" : "No");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int p[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
        }
        balance(p, n);
    }
    return 0;
}