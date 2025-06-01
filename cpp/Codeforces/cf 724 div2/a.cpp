// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 724 div2\a.cpp
 * @date      2025/04/14 19:09:38
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
    int max = -inf, flag = 0;
    while (n--) {
        int x;
        std::cin >> x;
        max = std::max(max, x);
        if (x < 0) flag = 1;
    }
    if (flag) {
        std::cout << "No" << ln;
    } else {
        std::cout << "Yes" << ln << max + 1 << ln;
        for (int i = 0; i <= max; ++i) std::cout << i << ' ';
        std::cout << ln;
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
