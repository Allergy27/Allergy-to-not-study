// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace luogu\day5\p2501.cpp
 * @date      2024/10/08 14:22:31
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
// #define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> qwq(n);
    for (auto &x : qwq) cin >> x;
    for (int i = 0; i < n; ++i) qwq[i] -= i;
    vector<int> dp;
    for (auto x : qwq) {
        if (dp.empty() || dp.back() <= x) {
            dp.emplace_back(x);
        } else {
            int i = upper_bound(dp.begin(), dp.end(), x) - dp.begin();
            if (i > 0) --i;
            dp[i] = x;
        }
    }
    int ans = inf, t = dp.size();
    vector<vector<int>> dpn(n, vector<int>(t+1));
    for (int k = 0; k < n; ++k) {
        int res = 0;
        for (int i = 0; i < k; ++i) res += abs(qwq[i] - qwq[0]);
        for (int i = k; i < n; ++i) res += abs(qwq[n - 1] - qwq[i]);
        ans = min(ans, res);
    }
    cout << n - t << '\n';
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
