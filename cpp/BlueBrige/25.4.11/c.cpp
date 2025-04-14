// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\BlueBrige\25.4.11\c.cpp
 * @date      2025/04/11 13:47:18
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
    int ans = 0;
    auto check = [](int x) {
        int tmp = x, flag = 1;
        while (tmp > 0) {
            if ((tmp % 10 % 2) != flag) return 0;
            flag ^= 1;
            tmp /= 10;
        }
        return 1;
    };
    for (int i = 1; i <= n; ++i)
        if (check(i)) ++ans;
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
