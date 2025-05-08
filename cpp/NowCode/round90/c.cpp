// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round90\c.cpp
 * @date      2025/04/20 19:20:04
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
    std::vector<int> a(n), b(n);
    for (auto &x : a) std::cin >> x;
    for (auto &x : b) std::cin >> x;
    for (int i = 0; i < n; ++i) a[i] *= i + 1;
    std::vector<PII> p(n);
    for (int i = 0; i < n; ++i) p[i] = {a[i], i};
    std::sort(p.begin(), p.end(), [](PII a, PII b) { return a.first < b.first; });
    std::sort(b.begin(), b.end());

    for (int i = 0; i < n; ++i) a[p[i].second] = b[i];

    for (int i = 0; i < n; ++i) std::cout << a[i] << ' ';
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
