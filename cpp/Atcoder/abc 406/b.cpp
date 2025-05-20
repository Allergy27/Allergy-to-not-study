/* Copyright 2025 Allergy
 * @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\Atcoder\abc 406\b.cpp
 * @date      2025/05/17 20:11:18
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define judge(x) std::cout << ((x) ? "Yes\n" : "No\n")

using ll = int64_t;
using PII = std::pair<int, int>;
using PDD = std::pair<double, double>;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int _ = 1;
    // std::cin >> _;

    auto solve = [&]() -> void {
        int n, m;
        std::cin >> n >> m;
        ll ans = 1, tmp = 1;
        for (int i = 0; i < m; ++i) tmp *= 10;
        for (int i = 0; i < n; ++i) {
            ll x;
            std::cin >> x;
            if (ans > tmp / x) {
                ans = 1;
            } else {
                ans *= x;
                if (ans >= tmp) ans = 1;
            }
        }
        std::cout << ans << ln;
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
