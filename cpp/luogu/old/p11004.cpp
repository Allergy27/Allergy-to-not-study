// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\p11004.cpp
 * @date      2025/03/19 17:56:32
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m, ans = 0;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> b(n);
    for (auto &x : a) std::cin >> x;
    for (auto &x : b) std::cin >> x;
    auto check = [](int x) {
        while (x) {
            int tmp = x % 10;
            if (tmp == 0 || tmp == 2 || tmp == 4) return 1;
            x /= 10;
        }
        return 0;
    };
    int w = 0;
    for (int i = 0; i < n; ++i) {
        int tmp = w ? check(b[i]) : check(a[i]);
        if (tmp) w ^= 1, ++ans;
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
