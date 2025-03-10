// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\winter_camp\Day 1\c.cpp
 * @date      2025/01/13 21:06:54
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    std::string s;
    std::cin >> n;
    std::cin >> s;
    std::vector<bool> tmp(26);
    for (int i = 0; i < n; ++i) {
        tmp[s[i] - 'a'] = true;
    }
    std::vector<char> r;
    for (int i = 0; i < 26; ++i) {
        if (tmp[i]) r.push_back(i + 'a');
    }
    std::map<char, char> mp;
    int m = r.size();
    for (int i = 0; i < m / 2; ++i) {
        mp[r[i]] = r[m - i - 1];
        mp[r[m - i - 1]] = r[i];
    }
    for (int i = 0; i < n; ++i) {
        if (mp[s[i]])
            std::cout << mp[s[i]];
        else
            std::cout << s[i];
    }
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
