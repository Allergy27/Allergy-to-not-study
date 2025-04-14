// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\BlueBrige\25.4.10\h.cpp
 * @date      2025/04/10 18:07:30
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
    std::vector<std::vector<int>> qwq(n + 2, std::vector<int>(m + 2));
    const std::vector<int> way = {-1, -1, 0, -1, 1, 0, 1, 1, -1};
    auto cal = [&](int x, int y) {
        if (qwq[x][y] == 1) return 9LL;
        int ans = 0;
        for (int i = 0; i < 8; ++i) ans += qwq[x + way[i]][y + way[i + 1]];
        return ans;
    };

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) std::cin >> qwq[i][j];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) std::cout << cal(i, j) << ' ';
        std::cout << ln;
    }
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
