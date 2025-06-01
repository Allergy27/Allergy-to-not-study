// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 977 div2\c1.cpp
 * @date      2025/04/18 17:34:38
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
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<int> qwq(n);
    for (auto &x : qwq) std::cin >> x;

    std::vector<int> mp(n + 1);
    int p = 0, flag = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        std::cin >> x;
        // 出现过
        if (mp[x]) continue;
        if (p < n && qwq[p] != x)
            flag = 1;
        else
            ++p;
        ++mp[x];
    }
    if (flag)
        std::cout << "TIDAK" << ln;
    else
        std::cout << "YA" << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
