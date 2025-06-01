// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1020 div3\d.cpp
 * @date      2025/04/24 23:10:02
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
    std::vector<int> a(n), b(m);
    for (auto &x : a) std::cin >> x;
    for (auto &x : b) std::cin >> x;

    std::vector<int> pre(m + 1);
    pre[0] = 0;
    int p = 0;
    for (int j = 1; j <= m; ++j) {
        while (p < n && a[p] < b[j - 1]) ++p;
        if (p < n) {
            pre[j] = p + 1;
            ++p;
        } else {
            pre[j] = n + 1;
        }
    }

    if (pre[m] <= n) {
        std::cout << "0\n";
        return;
    }

    std::vector<int> suf(m + 1);
    suf[m] = n;
    p = n - 1;
    for (int j = m - 1; j >= 0; --j) {
        int end = suf[j + 1] - 1;
        while (p > end) --p;
        while (p >= 0 && a[p] < b[j]) --p;
        if (p >= 0) {
            suf[j] = p;
            --p;
        } else {
            suf[j] = -1;
        }
    }

    int ans = -1;
    for (int j = 0; j < m; ++j) {
        if (pre[j] <= n && suf[j + 1] != -1 && pre[j] <= suf[j + 1])
            if (ans == -1 || b[j] < ans) ans = b[j];
    }

    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
