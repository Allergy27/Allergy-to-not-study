// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round92\f_fix.cpp
 * @date      2025/05/11 20:30:17
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define PII std::pair<int, int>

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int _ = 1;
    // std::cin >> _;

    auto solve = [&]() -> void {
        int n, m;
        std::cin >> n >> m;
        int tmp = 0, ans = 0;
        for (int i = 1; i <= n; ++i) tmp ^= i;
        for (int i = n + 1; i <= n + m; ++i) ans ^= i;
        if (tmp != ans) {
            std::cout << -1 << ln;
            return;
        }
        std::vector qwq(n, std::vector<int>(m));
        for (int i = 0; i < n - 1; ++i) qwq[i][m - 1] = i + 1;
        for (int i = 0; i < m - 1; ++i) qwq[n - 1][i] = n + 1 + i;
        qwq[n - 1][m - 1] = tmp;
        for (auto x : qwq) {
            for (auto y : x) std::cout << y << ' ';
            std::cout << ln;
        }
    };

    while (_--) solve();
    std::cin >> _;
    return 0;
}
