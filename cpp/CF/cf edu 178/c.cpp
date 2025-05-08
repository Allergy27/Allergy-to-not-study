// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf edu 178\c.cpp
 * @date      2025/04/29 14:53:58
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
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> a(n), b(n);

    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if (s[i] == 'A')
            a[i] = 1;
        else
            b[i] = 1, cnt++;

    if ((a[0] && b[n - 1] && (cnt == 1)) || (a[0] && a[n - 1]) || (a[n - 1] && a[n - 2]))
        std::cout << "Alice" << ln;
    else
        std::cout << "Bob" << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
