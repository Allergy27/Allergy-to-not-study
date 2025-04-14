// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\BlueBrige\25.4.8\Correct.cpp
 * @date      2025/04/08 22:05:45
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    std::string s;
    std::cin >> s;
    auto pre_func = [](std::string s) {
        int n = s.size(), tmp = 0;
        std::vector<int> pi(n);
        for (int i = 1; i < n; ++i) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j]) j = pi[j - 1];
            if (s[i] == s[j]) ++j;
            pi[i] = j;
            tmp = std::max(tmp, pi[i]);
        }
        return tmp;
    };
    int len = 0, n = s.size();
    while (n - 1 - len > len && s[len] == s[n - 1 - len]) ++len;

    s = s.substr(len, n - 2 * len);
    std::string t = s;
    std::reverse(s.begin(), s.end());

    std::string p[] = {t + '#' + s, s + '#' + t};
    std::cout << len + (std::max(pre_func(p[0]), pre_func(p[1])) + 1) / 2 << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
