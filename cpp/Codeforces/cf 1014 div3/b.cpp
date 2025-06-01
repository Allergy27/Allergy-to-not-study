// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1014 div3\b.cpp
 * @date      2025/04/08 11:56:07
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    std::cin >> n;
    std::string a, b;
    std::cin >> a >> b;
    std::vector<int> tmp_a(2), tmp_b(2);
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            ++tmp_a[a[i] - '0'];
            ++tmp_b[b[i] - '0'];
        } else {
            ++tmp_a[b[i] - '0'];
            ++tmp_b[a[i] - '0'];
        }
    }
    int p = (n + 1) / 2, q = n / 2;
    if (tmp_a[0] >= p && tmp_b[0] >= q)
        std::cout << "YES" << ln;
    else
        std::cout << "NO" << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
