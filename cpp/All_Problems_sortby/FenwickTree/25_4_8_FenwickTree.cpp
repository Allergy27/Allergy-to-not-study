// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\0x3f\25_4_8.cpp
 * @date      2025/04/09 19:38:52
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
    std::vector<std::vector<int>> qwq(4, std::vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) std::cin >> qwq[0][i];

    auto trans = [](int x) {
        int tmp = x, ans = 0;
        while (tmp > 0) {
            ans += tmp % 10;
            tmp /= 10;
        }
        return ans;
    };

    std::vector<int> qaq(n + 2);

    auto add = [&](int x, int v) {
        for (int i = x; i <= n; i += lowbit(i)) qaq[i] += v;
    };

    auto range_add = [&](int x, int y, int v) {
        add(x, v);
        add(y + 1, -v);
    };

    auto query = [&](int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) ans += qaq[i];
        return ans;
    };

    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= n; ++j) qwq[i][j] = trans(qwq[i - 1][j]);

    while (m--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, y;
            std::cin >> x >> y;
            range_add(x, y, 1);
        } else {
            int p;
            std::cin >> p;
            std::cout << qwq[std::min(query(p), 3LL)][p] << ln;
        }
    }
}
signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
