// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf edu 178\b.cpp
 * @date      2025/04/29 14:46:46
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
    std::vector<int> pre(n + 1);
    for (int i = 0; i < n; ++i) pre[i + 1] = pre[i] + qwq[i];

    std::vector<int> suf(n + 1);
    for (int i = 0; i < n; ++i) suf[i + 1] = std::max(suf[i], qwq[i]);
    for (int i = 0; i < n; ++i) std::cout << pre[n] - pre[n - i] + suf[n - i] << ' ';

    std::cout << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
