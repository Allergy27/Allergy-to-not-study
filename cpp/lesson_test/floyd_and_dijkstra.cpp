// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\lesson_test\floyd.cpp
 * @date      2025/04/02 17:11:34
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;
/* 样例输入
5 6
1 2 9
1 4 3
2 3 2
2 5 7
3 4 2
3 5 4
*/

struct node {
    int dis, u;

    bool operator>(const node &rhs) const { return dis > rhs.dis; }
};

void solve() {
    int n, m;
    std::cin >> n >> m;  // 节点数和边数

    std::vector<std::vector<std::pair<int, int>>> qwq(n);
    for (int i = 0; i < m; ++i) {
        int u, v, tmp;
        std::cin >> u >> v >> tmp;
        qwq[u - 1].push_back({v - 1, tmp});
        qwq[v - 1].push_back({u - 1, tmp});
    }

    auto floyd = [&]() {  // O(n^3) -> 任意两点的最短路
        std::vector<std::vector<int>> f(n, std::vector<int>(n, inf));
        for (int i = 0; i < n; ++i)
            for (auto [x, y] : qwq[i]) f[i][x] = y;

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j)
                    if (i != j)
                        f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
                    else
                        f[i][j] = 0;
            }
        }

        for (auto x : f) {
            for (auto y : x) std::cout << y << ' ';
            std::cout << ln;
        }
    };

    auto dijkstra = [&](int s) {  // O(n^2) -> 稠密图性能稍好
        std::vector<bool> vis(n);
        std::vector<int> dis(n, inf);
        dis[s] = 0;
        for (int i = 0; i < n; ++i) {
            int u = 0, mind = inf;
            for (int v = 0; v < n; ++v)
                if (!vis[v] && dis[v] < mind) u = v, mind = dis[v];
            vis[u] = 1;
            for (auto edge : qwq[u]) {
                int v = edge.first, w = edge.second;
                if (dis[v] > dis[u] + w) dis[v] = dis[u] + w;
            }
        }
        return dis;
    };

    auto dijkstra_heap = [&](int s) {  // O(mlogm)-> s到其他n个点的最短路,堆优化
        std::vector<bool> vis(n);
        std::vector<int> dis(n, inf);
        std::priority_queue<node, std::vector<node>, std::greater<node>> q;
        dis[s] = 0;
        q.push({0, s});
        while (!q.empty()) {
            int u = q.top().u;
            q.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (auto edge : qwq[u]) {
                int v = edge.first, w = edge.second;
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    q.push({dis[v], v});
                }
            }
        }
        return dis;
    };

    auto dijkstra_solve = [&]() {  // O(nmlogm) -> 相比floyd在稀疏图会有明显提升
        for (int i = 0; i < n; ++i) {
            auto p = dijkstra_heap(i);
            for (auto x : p) std::cout << x << ' ';
            std::cout << ln;
        }

        std::cout << ln;

        for (int i = 0; i < n; ++i) {
            auto p = dijkstra(i);
            for (auto x : p) std::cout << x << ' ';
            std::cout << ln;
        }
    };

    auto remake = [&]() {
        std::vector<std::vector<int>> graph = {
            {1, 4, 4, 4, 4}, {3, 2, 3, 3, 3}, {4, 2, 3, 4, 5}, {1, 3, 3, 4, 3}, {4, 3, 3, 3, 5}};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << i + 1 << " to " << j + 1 << " miniest way :" << ln;
                int p = graph[i][j];
                std::cout << i + 1 << " ->";
                while (p != j + 1) {
                    std::cout << p << " ->";
                    p = graph[p - 1][j];
                }
                std::cout << j + 1 << ln;
            }
        }
    };
    floyd();
    std::cout << ln;
    dijkstra_solve();
    remake();
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
