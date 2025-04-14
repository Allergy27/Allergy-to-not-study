// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1014 div3\c.cpp
 * @date      2025/04/08 14:41:20
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
    std::vector<int> qwq(n), tmp(2);
    for (auto &x : qwq) {
        std::cin >> x;
        int p = x & 1;
        ans += x - p;
        tmp[p] = std::max(tmp[p], x);
    }
    if (tmp[0] == -1 || tmp[1] == -1)
        std::cout << std::max(tmp[0], tmp[1]) << ln;
    else
        std::cout << ans + 1 << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
