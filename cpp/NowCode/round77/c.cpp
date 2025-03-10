// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round77\c.cpp
 * @date      2025/01/19 19:12:49
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m, a, b, c, d;
    std::cin >> n >> m >> a >> b >> c >> d;
    if (n % std::__gcd(c, d) == 0 && m % std::__gcd(a, b) == 0)
        std::cout << "YES" << ln;
    else
        std::cout << "NO" << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
