#include <stdio.h>

#define MAX_N 8  // 题目要求1<n<9，最大n为8

int main() {
    int n;
    scanf("%d", &n);
    
    int matrix[MAX_N][MAX_N] = {0};  // 初始化矩阵为0
    // 四个方向：右、下、左、上（dx为行偏移，dy为列偏移）
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int dir = 0;  // 初始方向：右
    int x = 0, y = 0;  // 初始位置：左上角(0,0)
    
    // 填充1~n²的数字
    for (int num = 1; num <= n * n; num++) {
        matrix[x][y] = num;  // 填充当前位置
        
        // 计算下一步位置
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        // 判断下一步是否越界或已填充：是则切换方向
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || matrix[nx][ny] != 0) {
            dir = (dir + 1) % 4;  // 切换方向（循环0-3）
            nx = x + dx[dir];     // 重新计算下一步位置
            ny = y + dy[dir];
        }
        
        // 更新当前位置为下一步位置
        x = nx;
        y = ny;
    }
    
    // 输出矩阵，每个数字占3个字符（空格补齐）
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", matrix[i][j]);  // %3d 自动补空格，占3位
        }
        printf("\n");  // 每行结束换行
    }
    
    return 0;
}