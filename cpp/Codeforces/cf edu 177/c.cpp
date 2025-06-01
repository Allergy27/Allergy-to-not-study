// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf edu 177\c.cpp
 * @date      2025/04/03 23:27:12
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    std::vector<int> d(n);
    for (auto &x : p) std::cin >> x;
    int ans = 0;
    std::set<int> past;
    for (auto &x : d) {
        std::cin >> x;
        int now = p[x - 1];  // 当前位置过去值
        p[x - 1] = x;
        while (past.find(now) == past.end()) {
            past.insert(now);
            ++ans;
            int tmp = now;
            now = p[now - 1];
            p[tmp - 1] = tmp;
        }
        std::cout << ans << ' ';
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
