// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1017 div4\b.cpp
 * @date      2025/04/14 10:21:21
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m, l, r;
    std::cin >> n >> m >> l >> r;
    int ansl = 0, ansr = 0;
    if (r > m) {
        std::cout << 0 << ' ' << m << ln;
    } else {
        int tmp = r - m;
        std::cout << tmp << ' ' << r << ln;
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
