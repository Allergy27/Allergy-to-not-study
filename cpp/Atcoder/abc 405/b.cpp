// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\Atcoder\abc 405\b.cpp
 * @date      2025/05/10 20:06:17
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
        std::vector<int> qwq(m);
        int tmp = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            if (qwq[x - 1]++ == 0 && ++tmp == m) ans = n - i;
        }
        std::cout << ans << ln;
    };

    while (_--) solve();
    std::cin >> _;
    return 0;
}
