// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\StarryCoding\p323.cpp
 * @date      2024/11/18 17:45:31
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
    vector<int> qwq(n), seat(m);
    for (auto &x : qwq) cin >> x;
    for (auto &x : seat) cin >> x;
    vector<bool> vis(n);
    vector<int> ans;
    auto dfs = [&](auto self, int i, int res) -> void {  // i表示搜索深度
        for (int j = 0; j < n; ++j) {
            if (!vis[j]) {  // 没有找过
                vis[j] = true;
                if (i == m - 1)
                    ans.emplace_back(res + qwq[j] * seat[i]);
                else
                    self(self, i + 1, res + qwq[j] * seat[i]);

                vis[j] = false;
            }
        }
    };
    dfs(dfs, 0, 0);
    sort(ans.begin(), ans.end());
    cout << (ans.end() - upper_bound(ans.begin(), ans.end(), (ans.back() / 2))) << ln;
}
signed main() {
    // ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
