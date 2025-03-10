// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 998 div3\a.cpp
 * @date      2025/01/19 22:35:16
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m, a, b;
    std::cin >> n >> m >> a >> b;
    std::vector<int> qvq = {n, m, 0, a, b};
    std::vector<int> qwq = {n + m, a - m, b - a};
    int ans = 0;
    for (auto x : qwq) {
        int tmp = 0;
        qvq[2] = x;
        for (int i = 0; i + 2 < 5; ++i)
            if (qvq[i] + qvq[i + 1] == qvq[i + 2]) ++tmp;
        ans = std::max(ans, tmp);
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
