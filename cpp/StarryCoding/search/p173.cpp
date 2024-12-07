// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\StarryCoding\p173.cpp
 * @date      2024/11/18 18:50:28
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
    vector<tuple<int, int, int>> qwq(n);
    int ans = 0;
    for (auto &[x, y, z] : qwq) cin >> x >> y >> z;
    vector<vector<int>> dis(n, vector<int>(n));
    vector<vector<int>> dp(1 << n, vector<int>(n, -ll_inf));
    for (int i = 0; i < n; ++i) {
        auto [x1, y1, z1] = qwq[i];
        for (int j = i + 1; j < n; ++j) {
            auto [x2, y2, z2] = qwq[j];
            dis[i][j] = abs(x1 - x2) + abs(y1 - y2);
            dis[j][i] = dis[i][j];
        }
        dp[1 << i][i] = z1 - abs(x1) - abs(y1);
    }

    for (int status = 0; status < (1 << n); ++status) {
        if (__builtin_popcount(status) == m) {
            for (int i = 0; i < n; ++i) ans = max(ans, dp[status][i]);
            continue;
        }
        for (int i = 0; i < n; ++i) {
            if ((status & (1 << i)) != 0) {
                for (int j = 0; j < n; ++j) {
                    if ((status & (1 << j)) == 0 && i != j) {
                        dp[status | (1 << j)][j] = max(dp[status | (1 << j)][j],
                                                       dp[status][i] + get<2>(qwq[j]) - dis[i][j]);
                    }
                }
            }
        }
    }
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
