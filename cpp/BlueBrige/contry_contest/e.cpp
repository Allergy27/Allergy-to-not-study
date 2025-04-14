// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\BlueBrige\contry_contest\e.cpp
 * @date      2025/03/14 15:08:41
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

    std::string a, b;
    std::cin >> a;
    std::cin >> b;
    std::sort(b.begin(), b.end());

    int l = 0, r = 0;
    while (l < n && r < m) {
        if (a[l] <= b[r])
            std::cout << a[l++];
        else
            std::cout << b[r++];
    }
    if (l < n && r == m) {
        for (int i = l; i < n; ++i) std::cout << a[i];
    }
    if (l == n && r < m) {
        for (int i = r; i < m; ++i) std::cout << b[i];
    }

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
