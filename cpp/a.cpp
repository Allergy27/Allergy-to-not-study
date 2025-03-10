// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\a.cpp
 * @date      2025/02/28 19:54:08
 */
#include <bits/stdc++.h>

#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t
#define A std::cout << "Alice" << ln
#define B std::cout << "Bob" << ln
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> qwq(n);
    for (auto &x : qwq) std::cin >> x;
    std::vector<int> l(n), r(n);
    for (int i = 1; i < n; ++i) l[i] = l[i - 1] + (qwq[i - 1] == -1);
    for (int i = n - 2; i >= 0; --i) r[i] = r[i + 1] + (qwq[i + 1] == -1);
    if (l[n - 1] % 2 == 0 || r[0] % 2 == 0) {
        std::cout << "Alice" << ln;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if ((l[i] / 2 + i) % 2 == (r[i] / 2 + n - i) % 2) {
            std::cout << "Alice" << ln;
            return;
        }
    }
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
