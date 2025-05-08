// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\0x3f\25_5_7.cpp
 * @date      2025/05/07 19:47:51
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t
#define PII std::pair<int, int>

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    const int MOD = 10000;
    std::cin >> n >> m;
    std::vector qwq(n + 1, std::vector<int>(m + 1));

    qwq[1][0] = 1;
    for (int i = 2; i <= n; i++) {
        int sum = 0;
        for (int j = 0; j <= m; j++) {
            (sum += qwq[i - 1][j]) %= MOD;
            qwq[i][j] = sum;
            if (j >= i - 1) sum = (sum - qwq[i - 1][j - i + 1] + MOD) % MOD;
        }
    }
    std::cout << qwq[n][m] << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
