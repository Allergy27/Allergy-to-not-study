// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1021 div2\a.cpp
 * @date      2025/05/08 19:04:11
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
    std::string n;
    std::cin >> n;
    std::map<int, int> qwq;
    for (auto x : n) qwq[x - '0']++;
    for (int i = 0; i < 10; ++i) {
        auto x = qwq.lower_bound(9 - i);
        std::cout << x->first;
        if (--x->second == 0) qwq.erase(x);
    }
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
