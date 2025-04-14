// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1011 edu\c.cpp
 * @date      2025/03/17 23:57:58
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
    std::cin >> n >> m;
    std::vector<int> qwq(m);
    for (auto &x : qwq) std::cin >> x;
    std::sort(qwq.begin(), qwq.end());

    auto f = [&](int x) -> int { return m - (std::lower_bound(qwq.begin(), qwq.end(), x) - qwq.begin()); };

    int64_t ans = 0;
    for (int i = 1; i < n; ++i) {
        int l = f(i);
        int r = f(n - i);
        int way = f(std::max(i, n - i));
        ans += l * r - way;
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
