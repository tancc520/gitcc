#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);  // 输入正整数a和整数b（b非负，题目隐含合理范围）
    
    // 1. a × 2^b
    int res1 = a << b;
    // 2. a ÷ 2^b（向下取整）
    int res2 = a >> b;
    // 3. 获取第b位
    int mask = 1 << b;
    int res3 = (a & mask) ? 1 : 0;
    // 4. 第b位置0
    int res4 = a & (~mask);
    // 5. 第b位置1
    int res5 = a | mask;
    // 6. 第b位取反
    int res6 = a ^ mask;
    
    // 依次输出结果
    printf("%d\n", res1);
    printf("%d\n", res2);
    printf("%d\n", res3);
    printf("%d\n", res4);
    printf("%d\n", res5);
    printf("%d\n", res6);
    
    return 0;
}