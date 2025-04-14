// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\BlueBrige\25.4.11\b.cpp
 * @date      2025/04/11 13:04:42
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int m = 233333, n = 343720;
    int dx = 15, dy = 17;
    int q = 2 * dx * m * 2 * n / std::__gcd(2 * m * dx, 2 * n);
    int p = q / dx * dy;
    double ans = sqrtl(q * q + p * p);
    std::cout << std::fixed << std::setprecision(2) << ans << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
