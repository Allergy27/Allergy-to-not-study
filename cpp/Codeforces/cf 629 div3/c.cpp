// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 629 div3\c.cpp
 * @date      2025/04/23 19:01:06
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
    int n, m;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int flag = n + 1;
    for (int i = 0; i < n; ++i) {
        if (flag < n + 1) {
            std::cout << 0;
            continue;
        }
        std::cout << (s[i] != '0');
        if (s[i] == '1') flag = i;
    }
    std::cout << ln;
    for (int i = 0; i < n; ++i) {
        if (i == flag) {
            std::cout << 0;
            continue;
        }
        if (i > flag)
            std::cout << s[i];
        else
            std::cout << (s[i] != '0');
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
