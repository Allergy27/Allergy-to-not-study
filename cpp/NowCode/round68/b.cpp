// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round68\b.cpp
 * @date      2024/11/17 19:18:37
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> tmp(n);
    for (auto &x : tmp) cin >> x;
    vector<vector<int>> qaq(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (tmp[i][j] == '*') qaq[i][j] = 1;
    // 计算二维前缀和
    vector<vector<int>> qwq(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            qwq[i][j] = qaq[i - 1][j - 1] + qwq[i - 1][j] + qwq[i][j - 1] - qwq[i - 1][j - 1];
    auto cot = [&](int x1, int y1, int x2, int y2) {
        return qwq[x2 + 1][y2 + 1] - qwq[x1][y2 + 1] - qwq[x2 + 1][y1] + qwq[x1][y1];
    };

    int ans = 0;
    int xx1 = 0, yy1 = 0, xx2 = 0, yy2 = 0;
    for (int x1 = 0; x1 < n; ++x1)
        for (int y1 = 0; y1 < m; ++y1)
            for (int x2 = 0; x2 < n; ++x2)
                for (int y2 = 0; y2 < m; ++y2)
                    if (cot(x1, y1, x2, y2) == 0 && (x2 - x1 + 1) * (y2 - y1 + 1) > ans) {
                        ans = max(ans, (x2 - x1 + 1) * (y2 - y1 + 1));
                        xx1 = x1;
                        yy1 = y1;
                        xx2 = x2;
                        yy2 = y2;
                    }
    cout << xx1 + 1 << ' ' << yy1 + 1 << ' ' << xx2 + 1 << ' ' << yy2 + 1 << ' ' << ln;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
