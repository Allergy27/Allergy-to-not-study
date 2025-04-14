// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\AcWing\p4905.cpp
 * @date      2025/03/18 21:03:06
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, tc, tm;
    std::cin >> n >> tc >> tm;
    std::vector<std::tuple<int, int, int>> qwq(n);
    for (auto &x : qwq) std::cin >> std::get<0>(x) >> std::get<1>(x) >> std::get<2>(x);
    auto check = [&](int x) {
        int l = std::max(static_cast<int>(0), x - tm + 1);
        int r = std::min(tc - 1, x);
        for (int i = 0; i < n; ++i) {
            int a = std::get<0>(qwq[i]), b = std::get<1>(qwq[i]), c = std::get<2>(qwq[i]);
            int k = c - a * tc - b * tm + b * x;
            if (a == b) {
                if (k < 0) return false;
            } else if (b > a) {
                r = std::min(r, static_cast<int>(std::floor(k / (b - a))));
            } else {
                l = std::max(l, static_cast<int>(std::ceil(k / (b - a))));
            }
        }
        return l <= r;
    };
    int l = 0, r = tc + tm - 2;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    std::cout << l << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
