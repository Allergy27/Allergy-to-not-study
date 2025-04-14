// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\BlueBrige\25.4.10\g.cpp
 * @date      2025/04/10 17:05:00
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    std::cin >> n;

    const int MOD = 1000000007;
    if (n <= 2) {
        std::cout << n << ln;
        return;
    }
    std::vector<int> old(3);
    std::vector<int> pre(3);
    std::vector<int> now(3);
    // 0 -> 完美 | 1 -> 上凸 | 2 -> 下凸
    old[0] = 1;
    pre[0] = 1;
    for (int i = 2; i <= n; ++i) {
        now[0] = (pre[0] + old[0] + pre[1] + pre[2]) % MOD;

        now[1] = (pre[1] + old[0]) % MOD;

        now[2] = (pre[2] + old[0]) % MOD;
        old = pre;
        pre = now;
    }
    std::cout << now[0] << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}