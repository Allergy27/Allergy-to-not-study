// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 629 div3\b.cpp
 * @date      2025/04/23 17:51:10
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
    std::cin >> n >> m;
    std::string s = std::string(n, 'a');
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += i;
        if (cnt >= m) {
            s[n - i - 1] = 'b';
            s[n - i + cnt - m] = 'b';
            break;
        }
    }
    std::cout << s << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
