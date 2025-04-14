// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1010 div2\a.cpp
 * @date      2025/03/15 22:14:01
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
    std::vector<std::string> qwq(n);
    for (auto &x : qwq) std::cin >> x;
    std::vector<int> row(n);
    std::vector<int> col(m);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) row[i] ^= qwq[i][j] - '0';
    for (int j = 0; j < m; ++j)
        for (int i = 0; i < n; ++i) col[j] ^= qwq[i][j] - '0';

    int rows = 0;
    for (int i = 0; i < n; ++i) rows += row[i];
    int cols = 0;
    for (int i = 0; i < m; ++i) cols += col[i];

    std::cout << std::max(rows, cols) << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
