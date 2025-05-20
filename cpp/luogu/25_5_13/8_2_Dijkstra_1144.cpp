// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\25_5_13\8_2_Dijkstra_1144.cpp
 * @date      2025/05/13 10:32:18
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define PII std::pair<int, int>

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int _ = 1;
    // std::cin >> _;

    auto solve = [&]() -> void {
        const int MOD = 100003;
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<PII>> qwq(n);
        std::vector<int> dis(n, inf), ans(n);
        auto dij = [&](int s) {
            std::priority_queue<PII> que;
            que.push({0, s});
            dis[s] = 0;
            ans[0] = 1;
            while (!que.empty()) {
                auto [current_w, u] = que.top();
                que.pop();
                if (current_w > dis[u]) continue;
                for (auto [w, v] : qwq[u]) {
                    if (dis[v] > dis[u] - w) {
                        dis[v] = dis[u] - w;
                        ans[v] = ans[u];
                        que.push({-dis[v], v});
                    } else if (dis[v] == dis[u] - w) {
                        (ans[v] += ans[u]) %= MOD;
                    }
                }
            }
        };
        for (int i = 0; i < m; ++i) {
            int u, v;
            std::cin >> u >> v;
            qwq[u - 1].push_back({-1, v - 1});
            qwq[v - 1].push_back({-1, u - 1});
        }

        dij(0);

        for (auto x : ans) std::cout << x << ln;
    };

    while (_--) solve();
    std::cin >> _;
    return 0;
}
