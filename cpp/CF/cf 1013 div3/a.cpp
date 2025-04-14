// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1013 div3\a.cpp
 * @date      2025/03/25 22:35:32
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
    std::vector<int> qwq(n);
    for (auto &x : qwq) std::cin >> x;
    std::map<int, int> mp;
    mp[0] = 3;
    mp[2] = 2;
    mp[1] = 1;
    mp[3] = 1;
    mp[5] = 1;
    int tmp = 5;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (mp.contains(qwq[i])) {
            mp[qwq[i]] -= 1;
            if (mp[qwq[i]] == 0) tmp -= 1;
        }
        if (tmp == 0) {
            ans = i + 1;
            break;
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
