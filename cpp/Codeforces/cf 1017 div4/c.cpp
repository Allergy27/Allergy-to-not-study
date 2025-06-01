// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1017 div4\c.cpp
 * @date      2025/04/14 10:27:50
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
    std::vector<std::vector<int>> qwq(n, std::vector<int>(n));
    for (auto &x : qwq)
        for (auto &y : x) std::cin >> y;
    std::vector<int> cnt(2 * n);
    std::vector<int> ans;
    for (int i = 0; i < n; ++i) {
        cnt[qwq[0][i] - 1] = 1;
        ans.emplace_back(qwq[0][i]);
    }
    for (int j = 1; j < n; ++j) {
        cnt[qwq[n - 1][j] - 1] = 1;
        ans.emplace_back(qwq[n - 1][j]);
    }
    for (int i = 0; i < 2 * n; ++i) {
        if (cnt[i] == 0) {
            std::cout << i + 1 << ' ';
            break;
        }
    }
    for (auto x : ans) std::cout << x << ' ';
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
