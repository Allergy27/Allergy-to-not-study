// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1014 div3\a.cpp
 * @date      2025/04/08 11:40:21
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, ma = 0, mi = ll_inf;
    std::cin >> n;
    std::vector<int> qwq(n);
    for (auto &x : qwq) {
        std::cin >> x;
        ma = std::max(ma, x);
        mi = std::min(mi, x);
    }
    std::cout << ma - mi << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
