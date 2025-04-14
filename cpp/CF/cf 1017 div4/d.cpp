// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1017 div4\d.cpp
 * @date      2025/04/14 10:36:20
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    std::string p, s;
    std::cin >> p;
    std::cin >> s;
    p += '$';
    s += '#';
    int n = p.size(), m = s.size();
    int cnt = 0, flag = 0;
    int u = 0, d = 0;
    while (d < m) {
        int tmp = 0;
        if (u >= n) {
            flag = 1;
            break;
        }
        if (p[u] == s[d]) {
            if (u > 0 && d > 0 && p[u] != p[u - 1]) cnt = 0;
            ++cnt;
            ++u, ++d;
            continue;
        }
        if (d == 0) {
            flag = 1;
            break;
        }
        while (s[d] == s[d - 1]) ++d, ++tmp;
        if (tmp > cnt) {
            flag = 1;
            break;
        }
        cnt = 0;
        if (p[u] != s[d]) {
            flag = u != n - 1 || d != m - 1;
            break;
        }
    }
    if (flag)
        std::cout << "NO" << ln;
    else
        std::cout << "YES" << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
