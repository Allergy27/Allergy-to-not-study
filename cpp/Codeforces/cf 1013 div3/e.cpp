// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1013 div3\e.cpp
 * @date      2025/03/25 23:44:32
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
    const int MAXN = 1e7 + 1;

    std::vector<int> primes;
    std::vector<bool> is_prime(MAXN, true);
    std::vector<int> qwq(MAXN);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAXN; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            qwq[i] = 1;
        }
        for (int j = 0; j < primes.size() && i * primes[j] < MAXN; ++j) {
            is_prime[i * primes[j]] = false;
            if (i % primes[j] == 0) {
                qwq[i * primes[j]] = qwq[i];
                break;
            } else {
                qwq[i * primes[j]] = qwq[i] + 1;
            }
        }
    }
    for (int i = 1; i < MAXN; ++i) qwq[i] += qwq[i - 1];
    while (t--) {
        int n;
        std::cin >> n;
        std::cout << qwq[n] << ln;
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
