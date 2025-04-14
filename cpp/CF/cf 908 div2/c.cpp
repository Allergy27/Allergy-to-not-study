// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 908 div2\c.cpp
 * @date      2025/04/14 15:04:30
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
    std::cin >> n >> m;
    std::vector<int> qwq(n);
    for (auto &x : qwq) std::cin >> x;
    int t = n - 1, flag = false;
    for (int i = 0; i <= n; ++i) {
        if (qwq[t] > n) {
            flag = true;
            break;
        }
        t = (t - qwq[t] + n) % n;
    }
    if (flag || m >= n)
        std::cout << "No" << ln;
    else
        std::cout << "Yes" << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
