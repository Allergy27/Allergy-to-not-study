// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\lesson_test\dp.cpp
 * @date      2025/03/27 15:19:15
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

/*
11 11 12 12 13
5 6 8 11 18
53
*/

void solve() {
    int n = 5;
    std::vector<std::vector<int>> qwq(n + 1, std::vector<int>(n + 1));
    std::vector<int> buy = {11, 11, 12, 12, 13};
    std::vector<int> fix = {5, 6, 8, 11, 18};
    qwq[0][0] = 0;  // [买][修]

    /*
    0 0 0 0 0
    0 0 0 0
    0 0 0
    0 0
    0
    */
    for (int d = 1; d <= n; ++d)
        for (int i = 0; i <= d; ++i)
            for (int j = 0; j <= d; ++j) {
                if (i + j == d) {
                    if (j == 0) qwq[i][j] = qwq[i - 1][j] + buy[d - 1];
                    // qwq[i][j] = qwq[i - 1][j] + buy[d - 1];
                    else if (i == 0)
                        qwq[i][j] = qwq[i][j - 1] + fix[j - 1];
                    else
                        qwq[i][j] = std::min(qwq[i][j - 1] + fix[j - 1], qwq[i - 1][j] + buy[d - 1]);
                    // qwq[i][j] = std::min(qwq[i][j - 1] + fix[j - 1], qwq[i - 1][j] + buy[d - 1]);
                }
            }
    int ans = inf;
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < n; ++j)
            if (i + j == 5) ans = std::min(ans, qwq[i][j]);

    for (auto x : qwq) {
        for (auto y : x) std::cerr << y << '\t';
        std::cerr << ln;
    }
    std::cout << ans << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
