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
    int n;
    std::cin >> n;
    std::string colors;
    std::cin >> colors;
    std::vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> t[i];
    }
    std::vector<std::vector<int>> dp(6, std::vector<int>(n, inf));
    for (int i = 0; i < 6; ++i)
        dp[i][0] = 0;

}
signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
