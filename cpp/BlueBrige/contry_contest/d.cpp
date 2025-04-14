// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\BlueBrige\contry_contest\d.cpp
 * @date      2025/03/14 14:44:01
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
    std::vector<int> qwq(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> qwq[i];

    auto check = [&](int x) -> bool {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) cnt += (qwq[i] - qwq[i - 1] + x - 1) / x - 1;
        return cnt < m;
    };
    int l = 1, r = 1e8;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    std::cout << l << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
