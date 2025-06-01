// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\Month111\d.cpp
 * @date      2025/03/07 20:10:37
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m, k;
    std::cin >> n >> m;
    std::vector<std::vector<int>> coin(n + 1, std::vector<int>(m + 1));
    std::vector<std::vector<int>> wall(n + 1, std::vector<int>(m + 1, ll_inf));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) std::cin >> coin[i][j];
    }
    std::cin >> k;

    for (int i = 0; i < k; ++i) {
        int x, y, v;
        std::cin >> x >> y >> v;
        wall[x][y] = v;
    }
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if ((!(i == 1 && j == 1)) && (wall[i][j] <= i + j - 2 || (dp[i - 1][j] == 0 && dp[i][j - 1] == 0))) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) + coin[i][j];
            ans = std::max(ans, dp[i][j]);
        }
    }

    std::cout << ans << ln;
}
signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
