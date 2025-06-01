// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 998 div3\d.cpp
 * @date      2025/01/19 23:43:56
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
    for (auto &x : qwq) std::cin >> x;
    for (int i = 1; i < n; ++i) {
        int tmp = std::min(qwq[i], qwq[i - 1]);
        qwq[i] -= tmp;
        qwq[i - 1] -= tmp;
    }
    for (int i = 1; i < n; ++i) {
        if (qwq[i] < qwq[i - 1]) {
            std::cout << "NO" << ln;
            return;
        }
    }
    std::cout << "YES" << ln;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
