#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);  // 输入幻方的阶数（奇数）
    
    // 初始化n×n的矩阵，初始值为0
    int** magic = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        magic[i] = (int*)calloc(n, sizeof(int));
    }

    // 1的初始位置：第一行中间列
    int row = 0;
    int col = n / 2;
    magic[row][col] = 1;

    // 填充2到n²的数字
    for (int k = 2; k <= n * n; k++) {
        int prev_row = row;
        int prev_col = col;  // 记录K-1的位置

        // 规则1：K-1在第一行但不在最后一列
        if (prev_row == 0 && prev_col != n - 1) {
            row = n - 1;
            col = prev_col + 1;
        }
        // 规则2：K-1在最后一列但不在第一行
        else if (prev_col == n - 1 && prev_row != 0) {
            row = prev_row - 1;
            col = 0;
        }
        // 规则3：K-1在第一行最后一列
        else if (prev_row == 0 && prev_col == n - 1) {
            row = prev_row + 1;
            col = prev_col;
        }
        // 规则4：既不在第一行也不在最后一列
        else {
            int new_row = prev_row - 1;
            int new_col = prev_col + 1;
            if (magic[new_row][new_col] == 0) {  // 右上方未填数
                row = new_row;
                col = new_col;
            } else {  // 右上方已填数，填在正下方
                row = prev_row + 1;
                col = prev_col;
            }
        }

        magic[row][col] = k;  // 填充当前数字K
    }

    // 输出幻方（每行用空格分隔）
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", magic[i][j]);
            if (j != n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    // 释放内存
    for (int i = 0; i < n; i++) {
        free(magic[i]);
    }
    free(magic);

    return 0;
}