// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\winter_camp\Day 5\horse.cpp
 * @date      2025/01/17 18:36:09
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;
    std::vector<std::vector<bool>> vis(n, std::vector<bool>(m));
    std::vector<std::vector<int>> ans(n, std::vector<int>(m, -1));
    std::queue<std::pair<int, int>> que;
    const int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    const int dy[8] = {2, 1, -1, -2, 2, 1, -1, -2};
    que.push({--x, --y});
    ans[x][y] = 0;
    vis[x][y] = true;
    while (!que.empty()) {
        auto [p, q] = que.front();
        que.pop();
        for (int i = 0; i < 8; ++i) {
            int u = p + dx[i], v = q + dy[i];
            if (u < 0 || u >= n || v < 0 || v >= m || vis[u][v]) continue;
            vis[u][v] = true;
            que.push({u, v});
            ans[u][v] = ans[p][q] + 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            std::cout << std::left << std::setw(5) << ans[i][j] << ' ';
        std::cout << ln;
    }
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
