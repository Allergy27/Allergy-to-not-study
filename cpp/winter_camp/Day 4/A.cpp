// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\winter_camp\Day 4\A.cpp
 * @date      2025/01/16 20:51:01
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
    std::cin >> n >> m;
    // 建图
    std::vector<std::vector<int>> qwq(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        qwq[a - 1].push_back(b - 1);
    }
    std::vector<int> vis(n);
    // 栈实现
    auto dfs = [&](int x) {
        std::vector<int> stk;
        stk.push_back(x);
        while (!stk.empty()) {
            int tmp = stk.back();
            stk.pop_back();
            if (vis[tmp]) continue;
            vis[tmp] = true;
            for (auto son : qwq[tmp]) {
                stk.push_back(son);
            }
        }
    };

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        dfs(i);  // 搜索
        for (auto x : vis)
            if (x) ++ans;
        std::fill(vis.begin(), vis.end(), false);
    }
    std::cout << ans << ln;

    /*
    // lambda 表达式
    auto dfs = [&](auto &&self, int x) {
        if (vis[x]) return;
        vis[x] = true;
        for (auto i : qwq[x]) self(self, i);
    };

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        dfs(dfs, i);  // 搜索
        for (auto x : vis)
            if (x) ++ans;
        std::fill(vis.begin(), vis.end(), false);
    }
    std::cout << ans << ln;
    */
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
