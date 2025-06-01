// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1013 div3\b.cpp
 * @date      2025/03/25 22:51:00
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
    std::vector<int> qwq(n);
    for (auto &x : qwq) std::cin >> x;
    std::sort(qwq.begin(), qwq.end(), std::greater<int>());
    int tmp = 0, ans = 0, num = 1;
    for (int i = 0; i < n; ++i) {
        if (tmp != 0) {
            ++num;
            if (qwq[i] * num >= m) tmp = 0, num = 1, ++ans;
            continue;
        }
        if (qwq[i] >= m)
            ++ans;
        else
            tmp = qwq[i];
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
