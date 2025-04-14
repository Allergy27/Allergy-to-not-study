// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\p3375.cpp
 * @date      2025/03/10 19:42:34
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    auto pre_func = [](const std::string &s) {
        int n = s.size();
        std::vector<int> pi(n);
        for (int i = 1; i < n; ++i) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j]) j = pi[j - 1];
            if (s[i] == s[j]) ++j;
            pi[i] = j;
        }
        return pi;
    };
    std::string text, pattern;
    std::cin >> text >> pattern;
    auto pi = pre_func(pattern + '#' + text);
    int n = pattern.size(), m = text.size();
    for (int i = n + 1; i <= n + m; ++i) {
        if (pi[i] == n) std::cout << i - 2 * n + 1 << ln;
    }
    for (auto x : pre_func(pattern)) std::cout << x << ' ';
    std::cout << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
