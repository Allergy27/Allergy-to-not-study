// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round90\f.cpp
 * @date      2025/04/20 19:42:49
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
    std::vector<PII> qwq(n);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        qwq[i] = {x, i};
    }
    std::sort(qwq.begin(), qwq.end(), [](PII a, PII b) { return a.first < b.first; });
    std::vector<int> ans(n);
    m = n;
    int tmp = 0;
    while (m > 0) {
        m >>= 1;
        ++tmp;
    }
    int cnt = 1 << tmp;
    for (int i = 0; i < n; ++i) ans[qwq[i].second] = cnt ^ qwq[i].first;
    for (auto x : ans) std::cout << x << ' ';
    std::cout << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
