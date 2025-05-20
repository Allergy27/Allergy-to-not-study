/* Copyright 2025 Allergy
 * @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\5_18_VP\j.cpp
 * @date      2025/05/18 13:47:26
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define judge(x) std::cout << ((x) ? "Yes\n" : "No\n")

using ll = int64_t;
using PII = std::pair<int, int>;
using PDD = std::pair<double, double>;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

class MaxFlow {
 public:
    struct Edge {
        int to;        // 目标节点
        int capacity;  // 容量
        int flow;      // 当前流量
        Edge *re;      // 反向边指针

        Edge(int t, int c) : to(t), capacity(c), flow(0), re(nullptr) {}

        // 剩余容量计算
        int rest() const { return capacity - flow; }
    };

    // 构造函数
    explicit MaxFlow(int nodes) : n(nodes), level(nodes), ptr(nodes) { qwq.resize(nodes); }

    void add(int from, int to, int capacity) {
        if (from == to) return;

        auto *e_to = new Edge(to, capacity);
        auto *e_re = new Edge(from, 0);

        e_to->re = e_re;
        e_re->re = e_to;

        qwq[from].emplace_back(e_to);
        qwq[to].emplace_back(e_re);
    }

    int64_t dinic(int source, int sink) {  // 源点 汇点
        int64_t max_flow = 0;

        while (bfs(source, sink)) {
            std::fill(ptr.begin(), ptr.end(), 0);
            while (int64_t flow = dfs(source, sink, std::numeric_limits<int64_t>::max())) max_flow += flow;
        }

        return max_flow;
    }

    ~MaxFlow() {  // 析构函数
        for (auto &edges : qwq)
            for (auto *x : edges) delete x;
    }
    void change(int from, int to, int flow) { qwq[from][to]->flow = flow; }

 private:
    int n;                                 // 节点数
    std::vector<int> level;                // 分层图
    std::vector<int> ptr;                  // 当前弧优化指针
    std::vector<std::vector<Edge *>> qwq;  // 原图

    bool bfs(int source, int sink) {
        std::fill(level.begin(), level.end(), -1);
        level[source] = 0;

        std::queue<int> que;
        que.push(source);

        while (!que.empty()) {
            int u = que.front();
            que.pop();

            for (const auto &v : qwq[u]) {
                if (v->rest() > 0 && level[v->to] == -1) {
                    level[v->to] = level[u] + 1;  // 深度+1
                    que.push(v->to);
                }
            }
        }

        return level[sink] != -1;  // 是否可以构建分层图
    }
    int64_t dfs(int u, int sink, int64_t cur_flow) {
        if (u == sink || cur_flow == 0) return cur_flow;
        for (int &i = ptr[u]; i < qwq[u].size(); ++i) {
            Edge *e = qwq[u][i];
            if (e->rest() > 0 && level[e->to] == level[u] + 1) {
                if (int64_t tmp = dfs(e->to, sink, std::min(cur_flow, static_cast<int64_t>(e->rest())))) {
                    e->flow += tmp;
                    e->re->flow -= tmp;
                    return tmp;
                }
            }
        }
        return 0;
    }
};

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int _ = 1;
    // std::cin >> _;

    auto solve = [&]() -> void {
        int n = 3;
        MaxFlow qwq(5);
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            qwq.add(0, i, x);
        }
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            qwq.change(0, i, x);
        }
        int m;
        std::cin >> m;
        for (int i = 0; i < 3; ++i) qwq.add(i, 4, m);
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
