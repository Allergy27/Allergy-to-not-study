// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1011 edu\b.cpp
 * @date      2025/03/17 22:50:03
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::pair<int, int>> qwq(n);
    std::vector<int> qaq(n);
    std::vector<int> find(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> qwq[i].first;
        qaq[i] = qwq[i].first;
        qwq[i].second = i;
    }
    std::sort(qwq.begin(), qwq.end());
    int ans = 0;
    for (int i = n - 1; i >= n - k; --i) {
        ans += qwq[i].first;
        find[qwq[i].second] = 1;
    }
    if (find[0] || find[n - 1]) {
        std::cout << ans + qwq[n - k - 1].first << ln;
        return;
    }
    if (k == 1) {
        std::cout << ans + std::max(qaq[0], qaq[n - 1]) << ln;
        return;
    }

    std::cout << ans + qwq[n - k - 1].first << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
