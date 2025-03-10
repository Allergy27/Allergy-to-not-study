// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\winter_camp\Day 1\d.cpp
 * @date      2025/01/13 21:13:21
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    std::string s;
    std::cin >> s;
    for (auto x : s) {
        if (x == 'B' || x == 'C' || x == 'D' || x == 'E' || x == 'F' || x == 'G' || x == 'J' ||
            x == 'K' || x == 'L' || x == 'N' || x == 'P' || x == 'Q' || x == 'R' || x == 'S' || x == 'Z') {
            std::cout << "NO" << ln;
            return;
        }
    }
    // 判断回文
    int n = s.size();
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - i - 1]) {
            std::cout << "NO" << ln;
            return;
        }
    }
    std::cout << "YES" << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
