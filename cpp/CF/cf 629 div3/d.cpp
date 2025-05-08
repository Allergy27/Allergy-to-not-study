// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 629 div3\d.cpp
 * @date      2025/04/23 19:12:53
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
    std::vector<int> qwq(n), qaq(n);
    for (auto &x : qwq) std::cin >> x;

    int flag = 0;
    int tmp = -1;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        if (qwq[i] != qwq[j]) flag = 1;
        if (qwq[i] == qwq[j]) tmp = j;
    }
    std::vector<int> ans(n, 1);
    if (flag == 0) {
        std::cout << 1 << ln;
    } else if (n % 2 == 0 || tmp != -1) {
        std::cout << 2 << ln;
        if (tmp == -1) tmp = 0;
        for (int i = 0; i < n; ++i) ans[(tmp + i) % n] = 1 + i % 2;
    } else {
        std::cout << 3 << ln;
        ans[0] = 3;
        for (int i = 1; i < n; ++i) ans[i] = 1 + i % 2;
    }
    for (auto x : ans) std::cout << x << ' ';
    std::cout << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
