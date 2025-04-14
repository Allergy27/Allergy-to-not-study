// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\p2672.cpp
 * @date      2025/01/16 13:53:32
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
    std::cin >> n;
    std::vector<std::pair<int, int>> qwq(n);
    for (auto &[x, _] : qwq) std::cin >> x;
    for (auto &[_, y] : qwq) std::cin >> y;
    sort(qwq.begin(), qwq.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
        return a.second > b.second;
    });
    std::vector<int> qaq(n + 1);
    for (int i = 0; i < n; ++i) qaq[i + 1] = qaq[i] + qwq[i].second;
    std::vector<int> a(n + 1);
    std::vector<int> b(n + 1);
    for (int i = 0; i < n; ++i) a[i + 1] = std::max(a[i], 2 * qwq[i].first);
    for (int i = n - 1; i >= 0; --i) b[i] = std::max(b[i + 1], 2 * qwq[i].first + qwq[i].second);
    for (int i = 0; i < n; ++i) std::cout << std::max(qaq[i + 1] + a[i + 1], qaq[i] + b[i + 1]) << ln;
}

signed main() {
    // std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
