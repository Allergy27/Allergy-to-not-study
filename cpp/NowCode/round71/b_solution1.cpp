// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round71\b.cpp
 * @date      2024/12/08 19:09:27
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    std::cin >> n;
    std::vector<char> a(n);
    std::vector<std::pair<int, int>> b(26, {-1, -1});
    for (auto &x : a) std::cin >> x;
    int ans = inf;
    for (int i = 0; i < n; ++i) {
        auto &x = b[a[i] - 'a'];
        if (x.first == -1)
            x.first = i, x.second = i;
        else
            ans = std::min(ans, std::min(i - x.second - 1, (x.first + n - 1 - i) % n)), x.second = i;
    }
    if (ans == inf) ans = -1;
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
