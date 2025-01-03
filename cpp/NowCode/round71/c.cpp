// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round71\c.cpp
 * @date      2024/12/08 19:17:58
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    std::string s;
    std::cin >> s;
    std::cout << std::set<char>(s.begin(), s.end()).size() << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
