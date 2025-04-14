// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1011 edu\d.cpp
 * @date      2025/03/18 00:09:07
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
    auto f = [](int x) {
        int cnt = 0;
        int p = x;

        while (p) ++cnt, p >>= 1;

        std::vector<int> qwq(cnt);
        for (int i = 0; x; ++i) {
            qwq[i] = (x & 1);
            x >>= 1;
        }
        return qwq;
    };

    auto x = f(n);
    auto y = f(m);
    n = x.size(), m = y.size();
    for (int i = 0; i < n && i < m; ++i) {
        if (x[i] != y[i]) {
            // if (m == n) {
            //     std::cout << (1 << (n - i)) << ln;
            //     return;
            // }
            std::cout << (1 << (n - i)) + (1 << (m - i)) << ln;
            return;
        }
    }
    std::cout << 2 << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
