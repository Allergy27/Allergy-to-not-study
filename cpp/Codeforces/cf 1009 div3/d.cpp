// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1009 div3\d.cpp
 * @date      2025/03/13 19:08:37
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::map<int, int> cnt;
    auto isqrt = [&](int x) {
        int val = sqrtl(x) + 5;
        while (val * val > x) val--;
        return val;
    };
    std::vector<int> qwq(n), radii(n);
    for (int &i : qwq) std::cin >> i;
    for (int &i : radii) std::cin >> i;
    for (int i = 0; i < n; i++) {
        int a = qwq[i], r = radii[i];
        for (int x = a - r; x <= a + r; x++) cnt[x] = std::max(cnt[x], 2 * isqrt(r * r - (x - a) * (x - a)) + 1);
    }
    int ans = 0;
    for (auto [x, c] : cnt) ans += c;
    std::cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
