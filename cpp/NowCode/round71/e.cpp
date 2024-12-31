// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round71\e.cpp
 * @date      2024/12/09 09:28:54
 */
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t
#define double long double
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;
void solve() {
    int n, m;
    std::cin >> n;
    std::map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        cnt[x] += y;
    }

    auto helen = [&](int a, int b, int c) -> double {
        double p = (a + b + c) / 2.0;
        double ans = sqrt(p * (p - a) * (p - b) * (p - c));
        return ans;
    };

    double ans = -1;
    int l = 0, r = 0;
    for (auto [x, y] : cnt) {
        if (y > 2) ans = std::max(ans, helen(x, x, x));
        if (y > 1 && l) ans = std::max(ans, helen(l, x, x));
        if (2 * r > x) ans = std::max(ans, helen(x, r, r));
        if (y > 1) r = x;
        if (y) l = x;
    }
    std::cout << std::fixed << std::setprecision(10) << ans << ln;
}
signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
