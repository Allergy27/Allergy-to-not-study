// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\BlueBrige\25.4.10\e.cpp
 * @date      2025/04/10 16:51:25
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

    const int MOD = 1000000007;

    std::cin >> n;
    std::vector<int> a(n);
    for (auto &x : a) std::cin >> x;

    std::cin >> m;
    std::vector<int> b(m);
    for (auto &x : b) std::cin >> x;

    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    while (b.size() < n) b.emplace_back(0);

    int ret = 1, ans = 0;
    for (int i = 0; i < n; ++i) {
        int tmp = std::max(a[i], b[i]) + 1;
        ans = (ans + (a[i] - b[i]) * ret) % MOD;
        ret = (ret * tmp) % MOD;
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
