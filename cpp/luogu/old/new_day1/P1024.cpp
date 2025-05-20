// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\new_day1\P1024.cpp
 * @date      2025/04/02 14:56:14
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    double a, b, c, d;
    std::cin >> a >> b >> c >> d;

    auto f = [&](double x) { return a * x * x * x + b * x * x + c * x + d; };

    for (int i = -100; i < 100; ++i) {
        double l = i, r = i + 1;
        double x1 = f(l), x2 = f(r);
        if (x1 == 0) {
            std::cout << std::fixed << std::setprecision(2) << l << ' ';
        } else {
            if (x1 * x2 < 0) {
                while (r - l >= 0.001) {
                    double mid = (l + r) / 2.0;
                    if (f(mid) * f(r) <= 0)
                        l = mid;
                    else
                        r = mid;
                }
                std::cout << std::fixed << std::setprecision(2) << r << ' ';
            }
        }
    }
    std::cout << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
