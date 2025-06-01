// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1021 div2\b.cpp
 * @date      2025/05/08 19:16:45
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
    std::cin >> n >> m;
    std::vector<int> qwq(n);
    for (auto &x : qwq) std::cin >> x;
    std::sort(qwq.begin(), qwq.end());
    int l = (n - m - 1) / 2, r = m + (n - m) / 2;
    std::cout << qwq[r] - qwq[l] + 1 << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
