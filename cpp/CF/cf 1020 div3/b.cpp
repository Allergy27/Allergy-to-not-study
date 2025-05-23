// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1020 div3\b.cpp
 * @date      2025/04/24 22:43:18
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
    for (int i = 0; i < n; ++i) qwq[i] = i;
    std::reverse(qwq.begin() + m, qwq.end());
    for (auto x : qwq) std::cout << x << ' ';
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
