// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\p8762.cpp
 * @date      2025/03/10 20:22:49
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int uint64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    auto f = [](int n) { return n * (n + 1) / 2; };

    auto sum = [](int n) { return n * (n + 1) * (n + 2) / 6; };

    auto find = [&](int n) {
        int l = 1, r = 1e7;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (f(mid) >= n)
                r = mid;
            else
                l = mid + 1;
        }
        return r;
    };

    int l, r;
    std::cin >> l >> r;
    int x = l - f(find(l) - 1), y = r - f(find(r) - 1);
    std::cout << sum(find(r) - 1) - sum(find(l) - 1) + f(y) - f(x - 1) << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
