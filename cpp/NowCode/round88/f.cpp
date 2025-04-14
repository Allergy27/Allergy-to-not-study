// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round88\f.cpp
 * @date      2025/04/06 20:02:36
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> qwq(n);
    for (auto &x : qwq) std::cin >> x;

    std::vector<int> tmp(n + 1);
    std::vector<int> dis(n + 1);
    tmp[n] = inf;
    for (int i = n - 1; i >= 0; --i) {
        tmp[i] = qwq[i] ? qwq[i] : tmp[i + 1];
        dis[i] = qwq[i] ? 0 : dis[i + 1] + 1;
    }
    for (int i = 1; i < n; ++i) {
        if (qwq[i] <= tmp[i]) {
            qwq[i] = qwq[i - 1] + 1;
        } else {
            qwq[i] = qwq[i - 1] - 1;
        }
    }
    for (auto x : qwq) std::cout << x << ' ';
    std::cout << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
