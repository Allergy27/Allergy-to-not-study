// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\practice138\e.cpp
 * @date      2025/05/10 12:33:39
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
        --m;
        std::vector<std::vector<int>> qwq(n);
        for (int i = 1; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            qwq[u - 1].emplace_back(v - 1);
            qwq[v - 1].emplace_back(u - 1);
        }

        std::vector dp(n, std::vector<int>(5));  // dp[u][k] 父节点到 u 长度为 k ,有多少条

        int ans = 0;
        auto dfs = [&](auto &&dfs, int u, int fa) -> void {
            dp[u][0] = 1;
            for (auto v : qwq[u]) {
                if (v == fa) continue;
                dfs(dfs, v, u);
                for (int i = 2; i < 5; ++i) {
                    for (int j = 0; j <= i; ++j) ans += dp[u][j] * dp[v][i - j];  // 到父节点 + 到子节点路径为2/3/4
                }
                for (int i = 0; i < 4; ++i)  // 到字节点路径都统计到父节点上
                    dp[u][i + 1] += dp[v][i];
            }
            return;
        };

        dfs(dfs, m, m);

        std::cout << ans << ln;
    };

    while (_--) solve();
    std::cin >> _;
    return 0;
}
