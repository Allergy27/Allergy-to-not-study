// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\Month111\c.cpp
 * @date      2025/03/07 19:28:22
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
    std::cin >> n;
    std::vector<std::string> qwq(n);
    for (auto &x : qwq) std::cin >> x;
    std::vector<int> pre(n);
    std::vector<int> suf(n);
    pre[0] = 1;
    suf[n - 1] = 1;
    int ans = 1;
    for (int i = 1; i < n; ++i) {
        if (qwq[i] == qwq[i - 1]) {
            pre[i] = pre[i - 1] + 1;
        } else {
            pre[i] = 1;
        }
        ans = std::max(ans, pre[i]);
    }
    for (int i = n - 2; i >= 0; --i) {
        if (qwq[i] == qwq[i + 1]) {
            suf[i] = suf[i + 1] + 1;
        } else {
            suf[i] = 1;
        }
        ans = std::max(ans, suf[i]);
    }
    for (int i = 1; i + 1 < n; ++i) {
        if (qwq[i] != qwq[i - 1] && qwq[i + 1] == qwq[i - 1]) ans = std::max(ans, pre[i - 1] + suf[i + 1]);
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
