// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1019 div2\b.cpp
 * @date      2025/04/22 15:22:24
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
    std::string s;
    std::cin >> s;

    s = '0' + s;
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans += 1 + (s[i] != s[i - 1]);

    int i = 0;
    int zo = 0, oz = 0;
    while (i + 1 <= n) {
        if (s[i + 1] == '1' && s[i] == '0') ++zo, ++i;
        ++i;
    }
    i = 0;
    while (i + 1 <= n) {
        if (s[i + 1] == '0' && s[i] == '1') ++oz, ++i;
        ++i;
    }
    if (zo > 1 || oz > 1) {
        std::cout << ans - 2 << ln;
    } else if (zo > 0 && oz > 0) {
        std::cout << ans - 1 << ln;
    } else {
        std::cout << ans << ln;
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
