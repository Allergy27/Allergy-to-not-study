// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\Atcoder\abc 398\d.cpp
 * @date      2025/03/22 20:04:41
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, r, c;
    std::cin >> n >> r >> c;
    int old_r = std::abs(r), old_c = std::abs(c);
    std::string s;
    std::cin >> s;
    for (auto x : s) {
        if (x == 'N')
            r += 1;
        else if (x == 'W')
            c += 1;
        else if (x == 'S')
            r -= 1;
        else if (x == 'E')
            c -= 1;
        std::cout << (r == 0 && c == 0);
    }
    std::cout << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
