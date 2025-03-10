// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\winter_camp\Day 5\A.cpp
 * @date      2025/01/17 19:48:40
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    const int m = 32768;
    std::vector<int> ans(m);
    std::vector<bool> vis(m);

    std::vector<std::vector<int>> qwq(m);
    for (int i = 1; i < m; ++i) {
        qwq[(i + 1) % m].push_back(i);
        qwq[(i * 2) % m].push_back(i);
    }

    auto bfs = [&]() {
        std::queue<std::pair<int, int>> que;
        que.push({0, 0});
        ans[0] = 0;
        vis[0] = true;
        while (!que.empty()) {
            auto [x, t] = que.front();
            que.pop();
            for (auto i : qwq[x]) {
                if (!vis[i]) {
                    vis[i] = true;
                    ans[i] = t + 1;
                    que.push({i, ans[i]});
                }
            }
        }
    };
    bfs();

    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int tmp;
        std::cin >> tmp;
        std::cout << ans[tmp] << ' ';
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
