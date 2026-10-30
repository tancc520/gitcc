#include <stdio.h>

int main() {
    int year, month;
    // 修正输入格式（原代码中逗号分隔错误，应为空格分隔）
    scanf("%d %d", &year, &month);
    int days;

    // 判断是否为闰年
    int is_leap = 0;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        is_leap = 1;
    }

    // 根据月份确定天数
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        case 2:
            days = is_leap ? 29 : 28;
            break;
        default:
            days = 0; // 无效月份（题目输入合法，可省略）
    }

    printf("%d\n", days);
    return 0;
}