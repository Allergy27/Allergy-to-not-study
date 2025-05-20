// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\Atcoder\abc 405\c.cpp
 * @date      2025/05/10 20:12:31
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
        std::cin >> n;
        std::vector<ll> qwq(n), qaq(n + 1);
        for (auto &x : qwq) std::cin >> x;
        for (int i = 0; i < n; ++i) qaq[i + 1] = qaq[i] + qwq[i];
        ll ans = 0;
        for (int i = 0; i < n; ++i) ans += qwq[i] * (qaq[n] - qaq[i + 1]);
        std::cout << ans << ln;
    };

    while (_--) solve();
    std::cin >> _;
    return 0;
}
