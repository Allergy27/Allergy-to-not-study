// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1010 div2\b.cpp
 * @date      2025/03/15 22:39:07
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m, x;
    std::cin >> x >> n >> m;
    auto ck = [](int x) {
        int cnt = 0;
        while (1 << cnt < x) ++cnt;
        return cnt;
    };
    if (n + m >= ck(x)) {
        std::cout << 0 << ' ' << 0 << ln;
        return;
    }
    int xmax = x, xmin = x;
    int maxop1 = n, maxop2 = m;
    int minop1 = n, minop2 = m;
    for (int i = 0; i < n + m; ++i) {
        // max
        if (maxop1 == 0) {
            xmax = (xmax + 1) / 2;
        } else if (maxop2 == 0) {
            xmax /= 2;
        } else if (xmax % 2 == 0) {
            xmax /= 2;
            --maxop1;
        } else {
            xmax = (xmax + 1) / 2;
            --maxop2;
        }
        // min
        if (minop1 == 0) {
            xmin = (xmin + 1) / 2;
        } else if (maxop2 == 0) {
            xmin /= 2;
        } else if (xmin % 2 == 1) {
            xmin /= 2;
            --minop1;
        } else {
            xmin = (xmin + 1) / 2;
            --minop2;
        }
    }
    std::cout << xmin << ' ' << xmax << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
