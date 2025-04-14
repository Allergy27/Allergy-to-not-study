// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\Atcoder\abc 397\d.cpp
 * @date      2025/03/15 20:26:07
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
    std::set<int> num;
    auto p = [](int x) -> int {
        for (int i = 1; i <= x; ++i) {
            if (i * i * i == x) return i;
        }
    };

    for (int i = 1; i <= 4000000; ++i) num.insert(i * i * i);
    for (auto x : num) {
        if (num.count(x - n) != 0) {
            std::cout << p(x) << ' ' << p(x - n) << ln;
            return;
        }
    }
    std::cout << -1 << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
