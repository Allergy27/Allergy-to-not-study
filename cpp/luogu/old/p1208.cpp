// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\p1208.cpp
 * @date      2025/01/16 12:31:58
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
    std::cin >> m >> n;
    std::vector<std::pair<int, int>> qwq(n);
    for (auto &[x, y] : qwq) std::cin >> x >> y;
    std::sort(qwq.begin(), qwq.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
        return a.first < b.first;
    });
    int tmp = 0;
    int ans = 0;
    for (auto [x, y] : qwq) {
        if (tmp + y >= m) {
            ans += x * (m - tmp);
            break;
        }
        tmp += y;
        ans += x * y;
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
