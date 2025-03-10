// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\Atcoder\abc 389\d.cpp
 * @date      2025/01/18 20:37:45
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, ans = 0;
    std::cin >> n;
    for (int i = 1  ; i < n; ++i)
        ans += std::floor(std::sqrt(n * n - (i + 0.5) * (i + 0.5)) - 0.5);
    std::cout << 4 * ans + 4 * n - 3 << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
