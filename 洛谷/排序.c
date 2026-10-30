#include <stdio.h>

#define MAXN 100005

int toward[MAXN];          /* 0 朝内，1 朝外 */
char job[MAXN][15];        /* 职业名，长度 <= 10 */

int main(void) {
    int n, m;
    if (scanf("%d%d", &n, &m) != 2) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d%s", &toward[i], job[i]);
    }

    int pos = 0;           /* 从第 1 个读入的小人开始 */
    for (int i = 0; i < m; i++) {
        int a, s;
        scanf("%d%d", &a, &s);

        if (toward[pos] != a) {
            pos = (pos + s) % n;          /* 逆时针方向走 */
        } else {
            pos = (pos - s + n) % n;      /* 顺时针方向走，+n 防负数 */
        }
    }

    printf("%s\n", job[pos]);
    return 0;
}
