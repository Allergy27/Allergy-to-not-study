// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\winter_camp\Day 1\e.cpp
 * @date      2025/01/13 21:19:14
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int a1, a2, b1, b2;
    std::cin >> a1 >> a2 >> b1 >> b2;
    std::vector<std::pair<int, int>> qwq = {{a1, b1}, {a1, b2}, {a2, b1}, {a2, b2}};
    int ans = 0;
    for (auto [x, y] : qwq) {
        int a = x > y;  // 第一轮a的胜负
        int b = x < y;
        a += a1 + a2 - x > b1 + b2 - y;  // 第二轮a的胜负
        b += a1 + a2 - x < b1 + b2 - y;
        if (a > b) ans++;
    }
    std::cout << ans << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
