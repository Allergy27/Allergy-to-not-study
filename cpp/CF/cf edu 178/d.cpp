// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf edu 178\d.cpp
 * @date      2025/04/29 15:14:09
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
    int t;
    std::cin >> t;

    const int N = 2000007;
    auto sieve = [&](int n) {
        std::vector<int> prime;
        std::vector<bool> is_prime(N, true);

        for (int i = 2; i <= n; ++i) {
            if (is_prime[i]) prime.emplace_back(i);
            for (auto x : prime) {
                if (i * x > n) break;
                is_prime[i * x] = false;
                if (i % x == 0) break;
            }
        }
        return prime;
    };

    std::vector<int> qwq = sieve(N);
    int len = qwq.size();
    std::vector<int> qaq(len + 1);
    for (int i = 0; i < len; ++i) qaq[i + 1] = qaq[i] + qwq[i];

    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        int sum = 0;
        for (auto &x : a) {
            std::cin >> x;
            sum += x;
        }
        std::sort(a.begin(), a.end());

        for (int i = 0; i < n; ++i) {
            if (qaq[n - i] <= sum) {
                std::cout << i << ln;
                break;
            }
            sum -= a[i];
        }
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
