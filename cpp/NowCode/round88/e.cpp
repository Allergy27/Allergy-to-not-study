// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round88\e.cpp
 * @date      2025/04/06 19:26:43
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> qwq = {std::vector<int>(n), std::vector<int>(n)};
    for (auto &x : qwq[0]) std::cin >> x;
    for (auto &x : qwq[1]) std::cin >> x;
    std::vector<std::vector<int>> dp(n, std::vector<int>(2));
    dp[0][0] = qwq[0][0];
    dp[0][1] = -ll_inf;
    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i - 1][0] + qwq[0][i];
        dp[i][1] = dp[i - 1][1] + qwq[1][i];
        if (dp[i - 1][1] >= m) dp[i][0] = std::max(dp[i][0], dp[i - 1][1] - m + qwq[0][i]);
        if (dp[i - 1][0] >= m) dp[i][1] = std::max(dp[i][1], dp[i - 1][0] - m + qwq[1][i]);
    }
    std::cout << std::max(dp[n - 1][0], dp[n - 1][1]) << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
