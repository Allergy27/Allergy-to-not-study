// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round71\d.cpp
 * @date      2024/12/08 19:43:39
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using ll = int;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;
void solve() {
    int n, m;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> qwq(n);
    for (auto &x : qwq) std::cin >> x;
    int ans = ll_inf;
    std::vector<int> order{0, 1, 2};
    do {
        std::vector dp(n + 1, std::vector<int>(3, ll_inf));
        dp[0] = {0, 0, 0};
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j <= i; ++j)
                    dp[k + 1][order[i]] = std::min(dp[k + 1][order[i]],
                                                   dp[k][order[j]] + (s[k] - '0' != order[i]) * qwq[k]);
        ans = std::min(ans, *std::min_element(dp[n].begin(), dp[n].end()));
    } while (std::next_permutation(order.begin(), order.end()));

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
