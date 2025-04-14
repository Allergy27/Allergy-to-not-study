// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\p1049.cpp
 * @date      2025/03/11 19:01:15
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
    std::vector<int> dp(n + 1);
    for (int i = 0; i < m; ++i) {
        int x;
        std::cin >> x;
        for (int j = n; j >= x; --j) dp[j] = std::max(dp[j], dp[j - x] + x);
    }
    std::cout << n - dp[n] << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
