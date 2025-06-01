// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1016 div3\c.cpp
 * @date      2025/04/08 22:51:45
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    auto check = [](int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    };
    int n, m;
    std::cin >> n >> m;
    if (m > 1) {
        if (n != 1) {
            std::cout << "NO" << ln;
        } else {
            for (int i = 1; i < m; ++i) n = n * 10 + 1;
            std::cout << (check(n) ? "YES" : "NO") << ln;
        }
    } else {
        std::cout << (check(n) ? "YES" : "NO") << ln;
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
