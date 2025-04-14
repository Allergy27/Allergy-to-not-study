// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\p1094.cpp
 * @date      2025/01/16 13:01:20
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
    std::cin >> m >> n;
    std::vector<int> qwq(n);
    for (auto &x : qwq) std::cin >> x;
    sort(qwq.begin(), qwq.end());
    int l = 0;
    int r = n - 1;
    int ans = 0;
    while (l <= r) {
        if (qwq[r] + qwq[l] <= m)
            ++l, --r, ++ans;
        else
            --r, ++ans;
    }
    std::cout << ans << ln;
}

signed main() {
    // std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
