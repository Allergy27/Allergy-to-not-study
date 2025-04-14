// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\p1158.cpp
 * @date      2025/03/10 14:26:09
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int x1, y1, x2, y2, n;
    std::cin >> x1 >> y1 >> x2 >> y2;
    std::cin >> n;
    std::vector<std::pair<int, int>> point(n);
    for (auto &[x, y] : point) std::cin >> x >> y;
    std::vector<std::pair<int, int>> dis(n);
    for (int i = 0; i < n; ++i) {
        dis[i].first = (point[i].first - x1) * (point[i].first - x1) + (point[i].second - y1) * (point[i].second - y1);
        dis[i].second = (point[i].first - x2) * (point[i].first - x2) + (point[i].second - y2) * (point[i].second - y2);
    }
    std::sort(dis.begin(), dis.end(),
              [](const std::pair<int, int> &a, const std::pair<int, int> &b) { return a.first < b.first; });
    int ans = dis[n - 1].first, d = 0;
    for (int i = n - 1; i >= 0; --i) {
        d = std::max(d, dis[i].second);
        int tmp = (i ? dis[i - 1].first : 0) + d;
        ans = std::min(ans, tmp);
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
