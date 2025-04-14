// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 794 div2\d.cpp
 * @date      2025/04/14 18:13:07
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::set<int> ab, ba;
    int cnta = s[0] == 'A', cntb = s[0] == 'B';
    for (int i = 1; i < n; ++i) {
        if (s[i] == 'B' && s[i - 1] == 'A') ab.insert(i - 1);
        if (s[i] == 'A' && s[i - 1] == 'B') ba.insert(i - 1);
        if (s[i] == 'A') ++cnta;
        if (s[i] == 'B') ++cntb;
    }
    int conab = 0, conba = 0;
    for (auto x : ab) {
        if (ba.find(x + 1) != ba.end()) ++conab;
    }
    for (auto x : ba) {
        if (ab.find(x + 1) != ab.end()) ++conba;
    }
    if (conab == 0 && conba == 0) {
        if (cnta - c - d == a && cntb - c - d == b)
            std::cout << "Yes" << ln;
        else
            std::cout << "No" << ln;
    } else {
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
