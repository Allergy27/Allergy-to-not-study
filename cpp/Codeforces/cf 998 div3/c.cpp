// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 998 div3\c.cpp
 * @date      2025/01/19 23:18:13
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
    std::unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int x;
        ++mp[x];
    }
    int ans = 0;
    for (auto &[x, cnt] : mp) {
        int y = m - x;
        if (x > y) continue;
        if (x == y) {
            ans += cnt / 2;
        } else {
            if (mp.find(y) != mp.end())
                ans += std::min(cnt, mp[y]);
        }
    }
    std::cout << ans << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
