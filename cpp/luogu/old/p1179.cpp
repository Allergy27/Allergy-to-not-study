// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\p1179.cpp
 * @date      2025/03/21 14:01:35
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    auto check = [](int x) {
        int cnt = 0;
        while (x > 0) cnt += x % 10 == 2, x /= 10;
        return cnt;
    };
    int n, m, ans = 0;
    std::cin >> n >> m;
    for (int i = n; i <= m; ++i) ans += check(i);
    std::cout << ans << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
