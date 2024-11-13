// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\flashmen\night_test\11_13.cpp
 * @date      2024/11/13 18:57:41
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
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> qwq(n, vector<int>(m));
    vector<int> cost(n);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
        for (auto &x : qwq[i]) cin >> x;
    }
    vector<int> skill(m);
    auto check = [&]() {
        for (auto t : skill)
            if (t < x) return false;
        return true;
    };
    int ans = inf;
    int res = 0;
    auto dfs = [&](auto self, int i) {
        if (i == n) {
            if (check()) ans = min(ans, res);
            return;
        }
        if (!check()) {
            res += cost[i];
            for (int j = 0; j < m; ++j) skill[j] += qwq[i][j];
            self(self, i + 1);
            for (int j = 0; j < m; ++j) skill[j] -= qwq[i][j];
            res -= cost[i];
        }
        self(self, i + 1);
    };
    dfs(dfs, 0);
    cout << (ans == inf ? -1 : ans) << ln;
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
