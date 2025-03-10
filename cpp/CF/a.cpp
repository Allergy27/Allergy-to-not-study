// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\a.cpp
 * @date      2025/01/20 23:41:01
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    std::cin >> n;
    std::vector<int> qwq(n);
    int odd = 0, even = 0;
    for (auto &x : qwq) {
        std::cin >> x;
        if (x & 1)
            odd++;
        else
            even++;
    }
    if (even == 0)
        std::cout << std::max(odd - 1, 0LL) << ln;
    else
        std::cout << odd + 1 << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
