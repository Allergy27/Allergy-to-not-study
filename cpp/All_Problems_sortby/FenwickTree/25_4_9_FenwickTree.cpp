// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\0x3f\a.cpp
 * @date      2025/04/09 20:45:36
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
    for (int i = 1; i <= n; ++i) range_add(i, n, 1);
    for (int i = 1; i <= n; ++i) std::cout << query(i) << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
