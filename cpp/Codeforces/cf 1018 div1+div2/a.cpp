// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1018 div1+div2\a.cpp
 * @date      2025/04/20 11:21:22
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
    std::vector<int> a(n), b(n);
    for (int i = n - 2; i >= 0; --i) {
        a[i] = a[i + 1] + (s[i] == '<');
        b[i] = b[i + 1] + (s[i] == '>');
    }
    std::cout << n - b[0] << ' ';
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '<') {
            std::cout << a[i] << ' ';
        } else {
            std::cout << n - b[i + 1] << ' ';
        }
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
