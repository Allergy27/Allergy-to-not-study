// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\BlueBrige\25.4.10\f.cpp
 * @date      2025/04/10 16:55:34
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
    std::cin >> n >> m >> k;
    std::vector<std::vector<int>> qaq(n + 1, std::vector<int>(m + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int tmp;
            std::cin >> tmp;
            qaq[i + 1][j + 1] = qaq[i + 1][j] + qaq[i][j + 1] - qaq[i][j] + tmp;
        }
    }

    auto check = [&](int x1, int y1, int x2, int y2) {
        return (qaq[x2 + 1][y2 + 1] - qaq[x2 + 1][y1] - qaq[x1][y2 + 1] + qaq[x1][y1]) <= k;
    };
    int ans = 0;
    for (int x1 = 0; x1 < n; ++x1)
        for (int x2 = x1; x2 < n; ++x2)
            for (int y1 = 0, y2 = 0; y1 < m; ++y1) {
                while (y2 < m && check(x1, y1, x2, y2)) ++y2;
                ans += y2 - y1;
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
