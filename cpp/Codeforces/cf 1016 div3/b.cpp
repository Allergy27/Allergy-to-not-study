// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1016 div3\b.cpp
 * @date      2025/04/08 22:42:32
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
    int tmp = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] != '0') tmp = i;
    }
    for (int i = 0; i < n; ++i) {
        if (i < tmp) ans += s[i] != '0';
    }
    ans += n - tmp;
    std::cout << ans - 1 << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
