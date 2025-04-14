// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\Atcoder\abc 397\b.cpp
 * @date      2025/03/15 20:05:49
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    int ans = 0;
    int tmp = 0;
    for (int i = 0; i < n; ++i) {
        if (tmp == 1 && s[i] == 'i') ++ans, tmp ^= 1;
        if (tmp == 0 && s[i] == 'o') ++ans, tmp ^= 1;
        tmp ^= 1;
    }
    if (s[n - 1] == 'i' && tmp == 1) ++ans;
    std::cout << ans << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
