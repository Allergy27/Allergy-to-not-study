// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\L.cpp
 * @date      2025/04/14 17:51:43
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
    std::vector<int> qwq(n);
    for (auto &x : qwq) std::cin >> x;
    std::sort(qwq.begin(), qwq.end());
    int cnt = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        cnt += qwq[i];
        double x = cnt * 1.0 / (i + 1);
        int t = std::upper_bound(qwq.begin(), qwq.end(), x) - qwq.begin();
        ans = std::max(ans, i - t + 1);
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
