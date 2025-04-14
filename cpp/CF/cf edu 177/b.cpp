// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf edu 177\b.cpp
 * @date      2025/04/03 22:44:56
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, k, x;
    std::cin >> n >> k >> x;
    std::vector<int> qwq(n);
    for (auto &x : qwq) std::cin >> x;
    std::vector<int> qaq(n + 1);
    for (int i = n - 1; i >= 0; --i) qaq[i] = qaq[i + 1] + qwq[i];
    int end = n * k;
    int tmp = x / qaq[0];
    int l = 0;
    if (tmp <= k) {
        for (int i = n; i >= 0; --i) {
            if (qaq[i] + tmp * qaq[0] >= x) {
                l = end - tmp * n - (n - i - 1);
                break;
            }
        }
    }
    std::cout << std::max(l, 0ll) << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
