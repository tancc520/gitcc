#include <stdio.h>

#define MAX_SIZE 50  // 题目要求n,m<50，数组大小设为50

// 统计(x,y)位置周围的地雷数量
int countMines(char mine[MAX_SIZE][MAX_SIZE], int n, int m, int x, int y) {
    int count = 0;
    // 遍历8个方向的偏移量（上、下、左、右、左上、右上、左下、右下）
    int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
    
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];  // 相邻行
        int ny = y + dy[i];  // 相邻列
        // 判断相邻位置是否在合法范围内，且是地雷
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && mine[nx][ny] == '*') {
            count++;
        }
    }
    return count;
}

int main() {
    int n, m;
    char mine[MAX_SIZE][MAX_SIZE];
    
    // 读取行数和列数
    scanf("%d %d", &n, &m);
    // 忽略换行符（避免读取行数后残留的换行影响后续输入）
    getchar();
    
    // 读取雷区分布
    for (int i = 0; i < n; i++) {
        fgets(mine[i], MAX_SIZE + 1, stdin);  // 读取整行（含换行）
        // 去除fgets读取的换行符（若有）
        int len = 0;
        while (mine[i][len] != '\0' && mine[i][len] != '\n') len++;
        mine[i][len] = '\0';
    }
    
    // 处理每个格子并输出结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mine[i][j] == '*') {
                // 地雷格直接输出*
                printf("*");
            } else {
                // 非地雷格统计周围地雷数，转为字符输出
                int cnt = countMines(mine, n, m, i, j);
                printf("%d", cnt);
            }
        }
        // 每行结束换行
        printf("\n");
    }
    
    return 0;
}