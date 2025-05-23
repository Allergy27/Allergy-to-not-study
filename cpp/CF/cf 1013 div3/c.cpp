// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1013 div3\c.cpp
 * @date      2025/03/25 23:10:15
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    /*
    1 5 4 3 2
    2 1 5 4 3
    3 2 1 5 4
    4 3 2 1 5

    1 7 6 5 4 3 2
    2 1 7 6 5 4 3
    . . .
    */
    int n;
    std::cin >> n;

    if (n % 2 == 0) {
        std::cout << -1 << ln;
        return;
    }
    for (int i = 0; i < n; ++i) std::cout << 2 * i % n + 1 << ' ';
    std::cout << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
