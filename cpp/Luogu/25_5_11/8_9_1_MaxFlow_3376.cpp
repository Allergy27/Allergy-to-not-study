// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\25_5_11\8_9_1_Dinic_3376.cpp
 * @date      2025/05/11 14:31:37
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define PII std::pair<int, int>

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

class Dinic {
 public:
    struct Edge {
        int to, cep;
        Edge *re;
        explicit Edge(int t, int c) : to(t), cep(c), re(nullptr) {}
    };
    explicit Dinic(int n) : level(n), ptr(n), qwq(n) {}

    void add(int u, int v, int w) {
        if (u == v) return;
        auto *eu = new Edge(v, w);
        auto *ev = new Edge(u, 0);
        eu->re = ev, ev->re = eu;
        qwq[u].emplace_back(eu);
        qwq[v].emplace_back(ev);
    }

    int64_t max_flow(int s, int t) {
        int64_t ans = 0;
        while (bfs(s, t)) {
            std::fill(ptr.begin(), ptr.end(), 0);
            while (int64_t tmp = dfs(s, t, ll_inf)) ans += tmp;
        }
        return ans;
    }

 private:
    std::vector<int> level, ptr;
    std::vector<std::vector<Edge *>> qwq;

    bool bfs(int s, int t) {
        std::fill(level.begin(), level.end(), -1);
        level[s] = 0;
        std::queue<int> que{{s}};
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (auto &v : qwq[u]) {
                if (v->cep > 0 && level[v->to] == -1) level[v->to] = level[u] + 1, que.push(v->to);
            }
        }
        return level[t] != -1;
    }

    int64_t dfs(int u, int t, int64_t flow) {
        if (u == t) return flow;
        for (int &i = ptr[u]; i < qwq[u].size(); ++i) {
            auto *e = qwq[u][i];
            if (e->cep > 0 && level[e->to] == level[u] + 1) {
                if (int64_t tmp = dfs(e->to, t, std::min(flow, static_cast<int64_t>(e->cep)))) {
                    e->cep -= tmp;
                    e->re->cep += tmp;
                    return tmp;
                }
            }
        }
        return 0;
    }
};

/*
4 5 4 3
4 2 30
4 3 20
2 3 20
2 1 30
1 3 30
*/

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int _ = 1;
    // std::cin >> _;

    auto solve = [&]() -> void {
        int n, m, s, t;
        std::cin >> n >> m >> s >> t;
        Dinic qwq = Dinic(n);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            std::cin >> u >> v >> w;
            qwq.add(u - 1, v - 1, w);
        }
        std::cout << qwq.max_flow(s - 1, t - 1) << ln;
    };

    while (_--) solve();
    std::cin >> _;
    return 0;
}
