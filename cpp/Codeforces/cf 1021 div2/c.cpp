// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1021 div2\c.cpp
 * @date      2025/05/08 19:27:50
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
    std::cin >> n;

    std::map<int, int> qwq;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        ++qwq[x];
    }

    bool ck = false;
    int pre = -1;
    for (auto [x, y] : qwq) {
        if ((y >= 4) || (ck && x == pre + 1 && y >= 2)) {
            std::cout << "Yes" << ln;
            return;
        }
        ck = (ck && x == pre + 1) || y >= 2;
        pre = x;
    }
    std::cout << "No" << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
