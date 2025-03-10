// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round77\b.cpp
 * @date      2025/01/19 19:03:52
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
    std::vector<int> qwq(n);
    std::vector<int> num(9);
    for (auto &x : qwq) {
        std::cin >> x;
        ++num[x - 1];
    }
    int mx = 0, mi = inf;
    for (auto x : num) {
        if (x == 0) {
            std::cout << "NO" << ln;
            return;
        }
        mi = std::min(mi, x);
        mx = std::max(mx, x);
    }
    if (mx - mi > 1) {
        std::cout << "NO" << ln;
        return;
    }
    std::cout << "YES" << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
