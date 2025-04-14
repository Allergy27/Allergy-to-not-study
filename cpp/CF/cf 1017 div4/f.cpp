// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1017 div4\f.cpp
 * @date      2025/04/14 11:38:05
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

    int gcdm = std::__gcd(m, k);
    int gcdn = std::__gcd(n, k / gcdm);
    int wm = m / gcdm;
    int wn = n / gcdn;

    for (int i = 0; i < wn; ++i) {
        for (int q = 0; q < gcdn; ++q) {
            for (int j = 0; j < wm; ++j) {
                int tmpn = (gcdm == 1) & (j & 1), tmpm = gcdm == 1 && (i & 1);
                for (int p = 0; p < gcdm; ++p) std::cout << (q * gcdm + p + tmpn + tmpm) % k + 1 << ' ';
            }
            std::cout << ln;
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
