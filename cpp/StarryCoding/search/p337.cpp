// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\StarryCoding\p337.cpp
 * @date      2024/11/18 18:30:47
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
    vector<int> qwq(n);
    for (auto &x : qwq) cin >> x;
    auto dfs = [&](auto self, int i, int res) -> int {  // i表示搜索深度
        int ans = 0;
        if (i == n) {
            return 1;
        }
        ans += self(self, i + 1, res);
        if (res + qwq[i] <= m)
            ans += self(self, i + 1, res + qwq[i]);
        return ans;
    };
    int ans = dfs(dfs, 0, 0);
    cout << ans << ln;
}

signed main() {
    // ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
