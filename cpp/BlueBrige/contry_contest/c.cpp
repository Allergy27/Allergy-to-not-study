// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\BlueBrige\contry_contest\c.cpp
 * @date      2025/03/13 20:51:05
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
    std::map<std::pair<int, int>, int> qwq;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        int dx = x2 - x1, dy = y2 - y1;
        int d = std::__gcd(std::abs(dx), std::abs(dy));
        dx /= d, dy /= d;
        int x = x1, y = y1;
        for (int i = 0;; ++i) {
            int x = x1 + i * dx, y = y1 + i * dy;
            ++qwq[{x, y}];
            if (x == x2 && y == y2) break;
        }
    }
    int ans = 0;
    for (auto [x, y] : qwq) {
        if (y > 1) ++ans;
    }
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
