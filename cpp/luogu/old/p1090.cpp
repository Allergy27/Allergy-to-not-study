// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\p1090.cpp
 * @date      2025/03/10 18:52:24
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
    std::priority_queue<int> qwq;
    for (int i = 0; i < n; ++i) {
        std::cin >> m;
        qwq.push(-m);
    }
    int ans = 0;
    while (!qwq.empty()) {
        int x = qwq.top();
        qwq.pop();
        if (qwq.empty()) continue;
        int y = qwq.top();
        qwq.pop();
        ans += -(x + y);
        qwq.push(x + y);
    }
    std::cout << ans << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
