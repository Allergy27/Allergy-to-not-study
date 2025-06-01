// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1023 div2\b.cpp
 * @date      2025/05/06 14:05:43
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t
#define PII std::pair<int, int>

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> qwq(n);
    int tot = 0;
    for (auto &x : qwq) {
        std::cin >> x;
        tot += x;
    }

    std::sort(qwq.begin(), qwq.end());

    int tmp = 0, flag = qwq[n - 1] - qwq[0] - 1 <= m;
    for (int i = 1; i < n; ++i) {
        if (!flag) break;
        if (qwq[i] - qwq[0] > m)
            if (++tmp > 1) flag = 0;
    }

    if (flag && (tot & 1))
        std::cout << "Tom" << ln;
    else
        std::cout << "Jerry" << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
