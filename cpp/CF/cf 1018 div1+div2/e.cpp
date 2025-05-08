// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1018 div1+div2\e.cpp
 * @date      2025/04/21 13:30:12
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
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> qwq(n);
    for (int i = 0; i < n; ++i) qwq[i] = (s[i] == 'P');
    auto qaq = qwq;
    std::sort(qaq.begin(), qaq.end());
    int ans = 0, tmp = 0;
    for (int i = 0; i < n; ++i) {
        if (!qwq[i]) ans += tmp--;
        ++tmp;
    }
    tmp = 0;
    for (int i = 0; i < n; i += 2) tmp += qwq[i] - qaq[i];
    ans += std::abs(tmp);
    std::cout << ans / 2 << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
