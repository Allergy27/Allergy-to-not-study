// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\Atcoder\abc 400\e.cpp
 * @date      2025/04/07 19:48:52
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int t;
    std::cin >> t;
    const int MAXN = 1e6 + 27;
    std::vector<int> primes, minp(MAXN), np(MAXN), lst(MAXN);
    for (int i = 2; i < MAXN; ++i) {
        if (minp[i] == 0) {
            minp[i] = i;
            np[i] = 1;
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p >= MAXN) break;
            minp[i * p] = p;
            if (p == minp[i]) {
                np[i * p] = np[i];
                break;
            }
            np[i * p] = np[i] + 1;
        }
    }

    for (int i = 1; i < MAXN; ++i) lst[i] = np[i] == 2 ? i : lst[i - 1];

    while (t--) {
        int n;
        std::cin >> n;
        n = std::sqrt(n);
        n = lst[n];
        n *= n;
        std::cout << n << ln;
    }
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
