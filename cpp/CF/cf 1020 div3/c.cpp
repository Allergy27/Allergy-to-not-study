// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1020 div3\c.cpp
 * @date      2025/04/24 22:48:41
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
    std::vector<int> a(n);
    std::vector<int> b(n);
    for (auto &x : a) std::cin >> x;
    for (auto &x : b) std::cin >> x;
    int ans = 0, tmp = -1, mx = 0, mi = m;
    for (int i = 0; i < n; ++i) {
        if (tmp == -1 && b[i] != -1) tmp = a[i] + b[i];

        if (tmp > -1 && b[i] != -1 && a[i] + b[i] != tmp) {
            std::cout << 0 << ln;
            return;
        }

        mx = std::max(mx, a[i]);
        mi = std::min(mi, a[i]);
    }
    if (tmp > -1 && (tmp > mi + m || tmp < mx)) {
        std::cout << 0 << ln;
        return;
    }
    if (tmp == -1) {
        std::cout << m + mi - mx + 1 << ln;
    } else {
        std::cout << 1 << ln;
    }
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
