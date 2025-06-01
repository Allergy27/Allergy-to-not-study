// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 998 div3\b.cpp
 * @date      2025/01/19 22:44:18
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
    std::vector<std::vector<int>> qwq(n, std::vector<int>(m));
    std::unordered_map<int, int> mp;
    for (auto &x : qwq)
        for (auto &y : x) std::cin >> y;
    for (auto &arr : qwq) {
        std::sort(arr.begin(), arr.end());
    }
    for (int i = 0; i < n; ++i) {
        mp[qwq[i][0]] = i + 1;
    }
    std::sort(qwq.begin(), qwq.end(), [](auto a, auto b) {
        return a[0] < b[0];
    });
    std::vector<int> ans;
    for (int j = 0; j < m; ++j)
        for (int i = 0; i < n; ++i) {
            ans.emplace_back(qwq[i][j]);
        }
    for (int i = 1; i < n * m; ++i) {
        if (ans[i] != ans[i - 1] + 1) {
            std::cout << -1 << ln;
            return;
        }
    }
    for (int i = 0; i < n; ++i)
        std::cout << mp[qwq[i][0]] << ' ';
    std::cout << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
