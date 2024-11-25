// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\Atcoder\abc 315\e.cpp
 * @date      2024/11/20 21:02:05
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
    cin >> n;
    vector<int> f(n, -1);
    vector<int> ck(n);
    for (int i = 0; i < n; ++i) {
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            if (i == 0 || ck[i]) ck[x - 1] = 1;
            if (ck[x - 1]) f[x - 1] = f[i] + 1;
        }
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i)
        if (f[i] != -1) ans.emplace_back(pair{i, f[i]});
    sort(ans.begin(), ans.end(), [&](auto x, auto y) {
        return x.second > y.second;
    });
    for (auto [x, y] : ans) {
        cout << x + 1 << ' ';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
