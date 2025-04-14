// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\BlueBrige\25.4.10\i_dp.cpp
 * @date      2025/04/11 09:36:19
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
    std::vector<std::vector<std::vector<int>>> f(n + 1, std::vector<std::vector<int>>(m + 1, std::vector<int>(m + 1)));
    const int MOD = 1000000007;
    f[0][0][2] = 1;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j) {
            for (int w = 0; w <= m; ++w) {
                if (j > 0 && w > 0) f[i][j][w] = f[i][j - 1][w + 1];
                if (i > 0 && w % 2 == 0) f[i][j][w] = (f[i][j][w] + f[i - 1][j][w / 2]) % MOD;
            }
        }
    std::cout << f[n][m - 1][1] << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
