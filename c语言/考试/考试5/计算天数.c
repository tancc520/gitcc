#include <stdio.h>

// 判断是否为闰年
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 计算从公元 0 年 1 月 1 日到指定日期的天数
int calculateDays(int year, int month, int day) {
    int days = 0;
    // 计算年份的天数
    for (int i = 0; i < year; i++) {
        days += isLeapYear(i) ? 366 : 365;
    }
    // 每个月的天数数组（非闰年）
    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // 计算月份的天数
    for (int i = 0; i < month - 1; i++) {
        days += monthDays[i];
        // 如果是闰年且月份大于 2，多加一天
        if (isLeapYear(year) && i == 1) {
            days++;
        }
    }
    // 加上日期的天数
    days += day;
    return days;
}

int main() {
    int startYear, startMonth, startDay;
    int endYear, endMonth, endDay;
    // 输入开始日期和结束日期
    scanf("%4d%2d%2d", &startYear, &startMonth, &startDay);
    scanf("%4d%2d%2d", &endYear, &endMonth, &endDay);

    // 计算开始日期和结束日期到公元 0 年 1 月 1 日的天数
    int startTotalDays = calculateDays(startYear, startMonth, startDay);
    int endTotalDays = calculateDays(endYear, endMonth, endDay);

    // 计算运输天数（结束日期天数 - 开始日期天数）
    int transportDays = endTotalDays - startTotalDays;

    // 输出运输天数
    printf("%d\n", transportDays);

    return 0;
}