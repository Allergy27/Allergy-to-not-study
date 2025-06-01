// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1017 div4\h.cpp
 * @date      2025/04/14 12:17:57
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
    auto f = [](int k, std::vector<int> a, int l, int r) {
        int ans = 0;
        for (int i = l; i <= r; ++i) {
            while (k % a[i] == 0) k = k / a[i];
            ans += k;
        }
        return ans;
    };

    for (int i = 1; i <= n; ++i) std::cin >> qwq[i];
    for (int i = 0; i < m; ++i) {
        int k, l, r;
        std::cin >> k >> l >> r;
        int res = f(k, qwq, l, r);
        std::cout << res << ln;
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
