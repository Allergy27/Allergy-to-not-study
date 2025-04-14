// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1009 div3\c.cpp
 * @date      2025/03/13 17:08:18
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
    std::cin >> n;
    m = lowbit(n);
    if (m == n) {
        std::cout << -1 << ln;
        return;
    }
    for (int i = 0; m + (1 << i) < n; ++i) {
        int tmp = m + (1 << i);
        int res = tmp ^ n;
        if (n + tmp > res && n - tmp < res) {
            std::cout << tmp << ln;
            return;
        }
    }
    std::cout << -1 << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
