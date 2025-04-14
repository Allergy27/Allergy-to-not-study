// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\Atcoder\abc 397\c.cpp
 * @date      2025/03/15 20:14:15
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
    for (auto &x : qwq) std::cin >> x;
    std::map<int, int> a, b;
    a[qwq[0]] = 1;
    for (int i = 1; i < n; ++i) ++b[qwq[i]];
    int ans = static_cast<int>(a.size() + b.size());
    for (int i = 1; i < n - 1; ++i) {
        ++a[qwq[i]], --b[qwq[i]];
        if (b[qwq[i]] == 0) b.erase(qwq[i]);
        ans = std::max(ans, static_cast<int>(a.size() + b.size()));
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
