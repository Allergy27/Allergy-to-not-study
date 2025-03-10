// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\p3131.cpp
 * @date      2025/01/16 14:19:56
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
    std::vector<int> qaq(n + 1);
    for (int i = 0; i < n; ++i) qaq[i + 1] = (qaq[i] + qwq[i]) % 7;
    // for (auto x : qaq) std::cout << x << ' ';
    // std::cout << ln;
    std::vector<int> ini(7, -1);
    std::vector<int> las(7);
    for (int i = 0; i <= n; ++i) {
        if (ini[qaq[i]] == -1) {
            ini[qaq[i]] = i;
        }
        las[qaq[i]] = i;
    }
    int ans = -1;
    for (int i = 0; i < 7; ++i) ans = std::max(ans, las[i] - ini[i]);
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
