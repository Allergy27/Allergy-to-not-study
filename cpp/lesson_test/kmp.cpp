// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\lesson_test\kmp.cpp
 * @date      2025/04/02 19:36:49
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    auto pre_func = [](std::string s) {
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

    auto kmp = [&](std::string s, std::string t) {  // s -> 原 t -> 查找
        std::string p = t + '#' + s;
        auto pi = pre_func(p);
        for (auto x : pi) std::cout << x << ' ';
        std::cout << ln;
    };
    kmp("abcbc", "bc");
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
