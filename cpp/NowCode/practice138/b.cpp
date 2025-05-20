// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\practice138\b.cpp
 * @date      2025/05/09 19:22:18
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
        std::vector<int> r(n);
        std::vector<int> c(m);
        for (auto &x : r) std::cin >> x;
        for (auto &x : c) std::cin >> x;
        std::sort(r.begin(), r.end());
        std::sort(c.begin(), c.end());
        int ans = 0;
        for (int i = 0; i < m; ++i) ans += c[i] * n;

        std::vector<int> qaq(m + 1);
        for (int i = 0; i < m; ++i) qaq[i + 1] = qaq[i] + c[i];
        for (int i = 0; i < n; ++i) {
            int p = std::lower_bound(c.begin(), c.end(), r[i]) - c.begin();
            ans += r[i] * p - qaq[p];
        }
        std::cout << ans << ln;
    };

    while (_--) solve();
    std::cin >> _;
    return 0;
}
