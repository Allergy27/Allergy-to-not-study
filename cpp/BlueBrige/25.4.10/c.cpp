// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\BlueBrige\25.4.10\c.cpp
 * @date      2025/04/10 16:41:33
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    int tmp = 5LL * n + 2LL * m;
    int res = k % tmp;
    if (res % tmp == 0) {
        std::cout << k / tmp * 7 << ln;
    } else {
        int ans = k / tmp * 7;
        for (int i = 0; i < 5; ++i) {
            ++ans;
            res -= n;
            if (res <= 0) {
                std::cout << ans << ln;
                return;
            }
        }
        for (int i = 0; i < 2; ++i) {
            ++ans;
            res -= m;
            if (res <= 0) {
                std::cout << ans << ln;
                return;
            }
        }
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
