// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\A.cpp
 * @date      2024/12/06 01:07:08
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> dp(n);
    int ans = 1;
    auto dfs = [&](this auto &&self, int x, int p) -> void {
        int v = adj[x].size() - 2;
        dp[x] = v;
        ans = std::max(ans, v + 2);
        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }
            self(y, x);
            ans = std::max(ans, dp[x] + dp[y] + 2);
            dp[x] = std::max(dp[x], v + dp[y]);
        }
    };
    dfs(0, -1);

    std::cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
