// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round77\f.cpp
 * @date      2025/01/19 20:32:51
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    std::cin >> n;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    std::cin >> m;
    std::vector<int> sz(n + 1);
    for (int i = 0; i < m; ++i) {
        int x;
        std::cin >> x;
        ++sz[x];
    }
    std::set<int> st;
    std::vector<int> ans(n);

    auto dfs = [&](auto &&self, int u, int fa) -> void {
        int d = 0;
        for (auto i : g[u]) {
            if (i == fa) continue;
            self(self, i, u);
            sz[u] += sz[i];
            d += sz[i] * sz[i];
        }
        ans[u] = sz[u] * sz[u] - d;
    };
    dfs(dfs, 1, 0);
    for (int i = 1; i <= n; ++i) {
        std::cout << ans[i] << ' ';
    }
    std::cout << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
