#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    cin >> n >> p;

    /* 1-based 差分数组，多开 2 位防 y+1 越界 */
    vector<int> d(n + 2, 0);

    /* 读入原成绩的同时直接建立差分：d[i] = a[i] - a[i-1] */
    int prev = 0;
    for (int i = 1; i <= n; i++){
        int v;
        cin >> v;
        d[i] = v - prev;
        prev = v;
    }

    /* p 次区间加，每次 O(1) */
    for (int i = 0; i < p; i++){
        int x, y, z;
        cin >> x >> y >> z;
        d[x]     += z;
        d[y + 1] -= z;
    }

    /* 前缀和还原，顺便求最小值 */
    int cur = 0;
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++){
        cur += d[i];
        ans = min(ans, cur);
    }

    cout << ans << '\n';
    return 0;
}
