// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round88\d.cpp
 * @date      2025/04/06 19:12:36
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
    int tmp = n, len = 0, flag = 1;
    while (tmp > 0) {
        if ((tmp & 1) == 0) {
            std::cout << (1 << len) << ln;
            flag = 0;
            break;
        }
        tmp >>= 1;
        ++len;
    }
    if (flag) std::cout << -1 << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
