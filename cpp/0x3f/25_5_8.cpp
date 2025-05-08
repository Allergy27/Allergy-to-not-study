// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\0x3f\25_5_8.cpp
 * @date      2025/05/08 14:57:48
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t
#define PII std::pair<int, int>

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    std::cin >> n;
    std::vector<int> qwq(n);
    for (auto &x : qwq) std::cin >> x;
    std::cin >> m;

    std::vector<int> f(n);
    while (m--) {
        int k;
        std::cin >> k;
        std::deque<int> dq;
        dq.push_back(0);
        for (int i = 1; i < n; ++i) {
            while (!dq.empty() && i - dq.front() > k) dq.pop_front();
            if (qwq[dq.front()] > qwq[i])
                f[i] = f[dq.front()];
            else
                f[i] = f[dq.front()] + 1;
            while (!f.empty() && f[dq.back()] > f[i] || (f[dq.back()] == f[i] && qwq[dq.back()] <= qwq[i]))
                dq.pop_back();
            dq.push_back(i);
        }
        std::cout << f[n - 1] << ln;
    }
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
