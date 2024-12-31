// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round71\b_solution2.cpp
 * @date      2024/12/09 18:17:30
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int std::int64_t

using ll = std::int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    s += s;
    std::vector<int> qwq(26, -1);
    int ans = n - 1;
    for (int i = 0; i < 2 * n; ++i) {
        if (qwq[s[i] - 'a'] != -1) ans = std::min(ans, i - qwq[s[i] - 'a'] - 1);
        qwq[s[i] - 'a'] = i;
    }
    std::cout << (ans == n - 1 ? -1 : ans) << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
