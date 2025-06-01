// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1018 div1+div2\b.cpp
 * @date      2025/04/20 12:40:51
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t
#define PII std::pair<int, int>

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> l(n);
    std::vector<int> r(n);
    int ans = 0;
    for (auto &x : l) std::cin >> x;
    for (auto &x : r) std::cin >> x;
    std::vector<int> qwq(n);
    for (int i = 0; i < n; ++i) {
        if (l[i] > r[i]) {
            ans += l[i];
            qwq.emplace_back(r[i]);
        } else {
            ans += r[i];
            qwq.emplace_back(l[i]);
        }
    }
    std::sort(qwq.begin(), qwq.end(), std::greater<int>());
    for (int i = 0; i < m - 1; ++i) ans += qwq[i];
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
