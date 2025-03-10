// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\winter_camp\Day 1\b.cpp
 * @date      2025/01/13 20:06:09
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    std::cin >> n >> m;
    if (m >= -1)
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
