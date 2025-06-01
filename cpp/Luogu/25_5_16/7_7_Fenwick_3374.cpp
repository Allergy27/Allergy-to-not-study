/* Copyright 2025 Allergy
 * @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\25_5_16\7_7_Fenwick_3374.cpp
 * @date      2025/05/16 18:26:07
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
        std::vector<ll> qwq(n + 1);
        auto query = [&](int i) -> ll {
            ll ans = 0;
            for (int j = i; j; j -= lowbit(j)) ans += qwq[j];
            return ans;
        };

        auto add = [&](int i, ll x) -> void {
            for (int j = i; j <= n; j += lowbit(j)) qwq[j] += x;
        };

        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            add(i + 1, x);
        }
        for (int i = 0; i < m; ++i) {
            int op;
            ll x, y;
            std::cin >> op >> x >> y;
            if (op == 1) {
                add(x, y);
            } else {
                ll ans = query(y) - query(x - 1);
                std::cout << ans << ln;
            }
        }
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
