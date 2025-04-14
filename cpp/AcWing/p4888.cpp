// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\AcWing\p4888.cpp
 * @date      2025/03/12 12:43:46
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
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int ini_diff = s[0] == 'G' ? s.find('H') : s.find('G');
    int las_same = s[0] == 'G' ? s.rfind('G') : s.rfind('H');
    int ans = 0;
    for (int i = 0; i < ini_diff; ++i) {
        int x;
        std::cin >> x;
        ans += (i > 0 && x > ini_diff) || (i == 0 && x > std::min(ini_diff, las_same));
    }
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
