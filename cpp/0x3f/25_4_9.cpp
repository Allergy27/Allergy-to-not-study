// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\0x3f\25_4_9.cpp
 * @date      2025/04/09 14:53:07
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
    std::vector<int> qaq(n + 1);

    for (int i = 1; i <= n; ++i) {
        std::cin >> qaq[i];
        qaq[i] += qaq[i - 1];
    }
    std::vector<int> f(n + 2);
    std::deque<int> q;
    q.push_back(0);
    for (int i = 1; i <= n; ++i) {
        if (q.front() < i - m) q.pop_front();  // f[L] - qaq[L] -> 单调队列维护滑动窗口最大值
        f[i + 1] = std::max(f[i], qaq[i] + f[q.front()] - qaq[q.front()]);
        while (!q.empty() && f[q.back()] - qaq[q.back()] <= f[i] - qaq[i]) q.pop_back();
        q.push_back(i);
    }
    std::cout << f[n + 1] << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
