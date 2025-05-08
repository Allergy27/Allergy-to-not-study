// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1023 div2\c.cpp
 * @date      2025/05/06 13:13:50
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
    std::string s;
    std::cin >> s;
    std::vector<int> qwq(n);

    const int END = -1e18;

    for (int i = 0; i < n; ++i) {
        std::cin >> qwq[i];
        if (s[i] == '0') qwq[i] = END;
    }

    std::vector<int> pre(n + 1), suf(n + 1);

    for (int i = 0; i < n; ++i) pre[i + 1] = std::max(pre[i] + qwq[i], qwq[i]);
    for (int i = n; i > 0; --i) suf[i - 1] = std::max(suf[i] + qwq[i - 1], qwq[i - 1]);

    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            qwq[i] = m - std::max(suf[i + 1], 0LL) - std::max(pre[i], 0LL);
            break;
        }
    }

    for (int i = 0; i < n; ++i) pre[i + 1] = std::max(pre[i] + qwq[i], qwq[i]);

    int res = *std::max_element(pre.begin(), pre.end());

    if (res == m) {
        std::cout << "Yes" << ln;
        for (auto x : qwq) std::cout << x << ' ';
        std::cout << ln;
    } else {
        std::cout << "No" << ln;
    }
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
