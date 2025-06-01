// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1017 div4\e.cpp
 * @date      2025/04/14 11:10:10
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m = 0;
    std::cin >> n;
    std::vector<int> qwq(n);
    std::vector<int> qaq(32);
    auto f = [&](int x) {
        int cnt = 0, tmp = x;
        while (tmp > 0) {
            if (tmp & 1) ++qaq[cnt];
            tmp >>= 1;
            ++cnt;
        }
        m = std::max(m, cnt + 1);
    };

    for (auto &x : qwq) {
        std::cin >> x;
        f(x);
    }
    auto find = [&](int res) {
        int cnt = 0, tmp = res, ans = 0;
        while (cnt < m) {
            int time = (tmp & 1) ? n - qaq[cnt] : qaq[cnt];
            ans += time * (1 << cnt);
            tmp >>= 1;
            ++cnt;
        }
        return ans;
    };
    int ans = 0;
    for (auto x : qwq) ans = std::max(ans, find(x));
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
