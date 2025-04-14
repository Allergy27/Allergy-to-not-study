// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\BlueBrige\25.4.7\h.cpp
 * @date      2025/04/07 15:30:53
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
    std::vector<std::vector<PII>> qwq(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        qwq[u - 1].push_back({v - 1, w});
        qwq[v - 1].push_back({u - 1, w});
    }

    // Dijkstra
    std::vector<bool> vis(n);
    std::vector<int> dis(n, ll_inf);
    std::vector<int> minist_cnt(n);
    std::vector<int> ans(n);
    std::vector<int> pre_min(n);
    std::vector<std::set<int>> fa(n);
    std::priority_queue<PII, std::vector<PII>, std::greater<PII>> q;
    dis[0] = 0;
    minist_cnt[0] = 1;
    pre_min[0] = 0;
    q.push({0, 0});  // dis pos
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        ans[u] = pre_min[u] + minist_cnt[u] - 1;
        for (auto [v, w] : qwq[u]) {
            fa[v].insert(u);
            if (dis[v] == dis[u] + w) {
                ++minist_cnt[v];
                pre_min[v] = std::min(ans[u], pre_min[v]);
            } else if (dis[v] > dis[u] + w) {
                minist_cnt[v] = 1;
                pre_min[v] = ans[u];
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
    for (int i = 0; i < n; ++i) std::cout << (dis[i] == ll_inf ? -1 : ans[i]) << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
