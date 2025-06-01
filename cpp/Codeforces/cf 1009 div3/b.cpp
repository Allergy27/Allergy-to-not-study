// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1009 div3\b.cpp
 * @date      2025/03/13 17:02:47
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
        int x;
        std::cin >> x;
        qwq.push(x);
    }
    while (!qwq.empty()) {
        int x = qwq.top();
        qwq.pop();

        if (qwq.empty()) {
            std::cout << x << ln;
            return;
        }
        int y = qwq.top();
        qwq.pop();

        qwq.push(x + y - 1);
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
