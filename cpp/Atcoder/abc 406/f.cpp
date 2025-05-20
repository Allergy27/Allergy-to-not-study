/* Copyright 2025 Allergy
 * @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\Atcoder\abc 406\f.cpp
 * @date      2025/05/17 21:28:05
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

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int _ = 1;
    // std::cin >> _;

    auto solve = [&]() -> void {
        int n, m;
        std::cin >> n;
        std::vector<ll> fen(n * 2 + 1);
        auto query = [&](int i) -> ll {
            ll ans = 0;
            for (int j = i; j; j -= lowbit(j)) ans += fen[j];
            return ans;
        };

        auto add = [&](int i, ll x) -> void {
            for (int j = i; j <= 2 * n; j += lowbit(j)) fen[j] += x;
        };

        auto range_sum = [&](int x, int y) -> ll { return query(y) - query(x - 1); };

        std::vector<std::vector<int>> qwq(n + 1);
        std::vector<PII> edges;
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            std::cin >> u >> v;
            edges.push_back({u, v});
            qwq[u].emplace_back(v);
            qwq[v].emplace_back(u);
        }
        std::cin >> m;
        std::vector<PII> tmp(n + 1);
        int z = 0;
        std::vector<int> depth(n + 1, -1);
        depth[1] = 0;
        auto dfs = [&](auto &&dfs, int i, int fa) -> void {
            tmp[i].first = ++z;
            for (auto x : qwq[i]) {
                if (x != fa) {
                    depth[x] = depth[i] + 1;
                    dfs(dfs, x, i);
                }
            }
            tmp[i].second = ++z;
        };
        dfs(dfs, 1, 1);
        for (int i = 1; i < 2 * n + 1; ++i) add(i, 1);
        for (int i = 0; i < m; ++i) {
            int op;
            std::cin >> op;
            if (op == 1) {
                int x, w;
                std::cin >> x >> w;
                add(tmp[x].first, w);
                add(tmp[x].second, w);
            } else {
                int y;
                std::cin >> y;
                auto [a, b] = edges[y - 1];

                y = (depth[a] > depth[b]) ? a : b;

                std::cout << std::abs(query(2 * n) - 2 * range_sum(tmp[y].first, tmp[y].second)) / 2 << ln;
            }
        }
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
