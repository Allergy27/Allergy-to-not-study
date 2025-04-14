// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\p9423.cpp
 * @date      2025/03/31 19:51:22
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

    auto dis = [](std::pair<int, int> a, std::pair<int, int> b) {
        int dx1 = a.first - b.first, dy1 = a.second - b.second;
        return dx1 * dx1 + dy1 * dy1;
    };

    std::vector<std::pair<int, int>> qwq(n);
    for (int i = 0; i < n; ++i) std::cin >> qwq[i].first >> qwq[i].second;
    for (int i = 0; i < n; ++i) {
        std::unordered_map<int, std::map<std::pair<int, int>, int>> qaq;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            int x = dis(qwq[i], qwq[j]);
            int nx = qwq[i].first - qwq[j].first, ny = qwq[i].second - qwq[j].second;
            int g = nx != 0 && ny != 0 ? std::__gcd(std::abs(nx), std::abs(ny)) : 1;
            qaq[x][{nx / g, ny / g}]++;
        }
        for (auto [_, m] : qaq) {
            for (auto [tmp, _] : m) {
                int x = tmp.first, y = tmp.second;
                if (m.count({-x, -y}))
                    ans += static_cast<int>(m.size() - 2);
                else
                    ans += static_cast<int>(m.size() - 1);
            }
        }
    }
    std::cout << ans / 2 << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
