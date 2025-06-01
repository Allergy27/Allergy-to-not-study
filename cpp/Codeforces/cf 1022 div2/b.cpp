// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1022 div2\b.cpp
 * @date      2025/05/07 12:35:00
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
    std::cin >> n >> m;
    int bits = __builtin_popcountll(m);
    if (n <= bits) {
        std::cout << m << ln;
        return;
    }
    if ((n - bits) % 2 == 0) {
        std::cout << m + n - bits << ln;
    } else {
        if (m > 1) {
            std::cout << m + n - bits + 1 << ln;
        } else if (m == 1) {
            std::cout << n + 3 << ln;
        } else {
            if (n == 1) {
                std::cout << -1 << ln;
            } else {
                std::cout << n + 3 << ln;
            }
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
