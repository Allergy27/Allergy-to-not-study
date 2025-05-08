// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1021 div2\c.cpp
 * @date      2025/04/26 18:26:54
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
    std::vector<int> qwq(n);
    std::map<int, int> check;
    for (auto &x : qwq) {
        std::cin >> x;
        check[x]++;
    }
    std::map<int, bool> a;
    std::map<int, bool> b;

    for (auto &[x, y] : check) {
        if (y > 3) {
            std::cout << "Yes" << ln;
            return;
        }
        if (y > 1) {
            a[x] = true;
            b[x + 1] = true;
            y -= 2;
        }
    }
    for (auto [x, y] : b) a[x] |= y;
    for (auto [x, y] : check) {
        if (y == 0) continue;
        if (a[x] && a[x + 1]) {
            std::cout << "Yes" << ln;
            return;
        }
        if (a[x]) a[x + 1] = 1;
    }
    std::cout << "No" << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
