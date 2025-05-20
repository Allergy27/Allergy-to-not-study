// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\practice138\c.cpp
 * @date      2025/05/09 19:34:36
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
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<int>> qwq(n);
        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            qwq[u - 1].emplace_back(v - 1);
            qwq[v - 1].emplace_back(u - 1);
        }

        auto dfs = [&](auto &&dfs, int u, int fa, int ans) -> int {
            int res = ans;
            for (auto x : qwq[u]) {
                if (x == fa) continue;
                res = std::max(res, dfs(dfs, x, u, ans + 1));
            }
            return res;
        };
        std::cout << dfs(dfs, m - 1, m - 1, 1) << ln;
    };

    while (_--) solve();
    std::cin >> _;
    return 0;
}
