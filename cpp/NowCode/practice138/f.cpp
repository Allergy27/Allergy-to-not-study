// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\practice138\f.cpp
 * @date      2025/05/10 13:12:59
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define PII std::pair<int, int>

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int _ = 1;
    std::cin >> _;

    auto sieve = [](int n) -> std::pair<std::vector<int>, std::vector<bool>> {
        std::vector<int> prime;
        std::vector<bool> not_prime(n + 1);
        for (int i = 2; i <= n; ++i) {
            if (!not_prime[i]) prime.emplace_back(i);
            for (auto x : prime) {
                if (i * x > n) break;
                not_prime[i * x] = true;
                if (i % x == 0) break;
            }
        }
        return {prime, not_prime};
    };
    auto [prime, not_prime] = sieve(270000);
    for (int i = 0; i < 3; ++i) not_prime[i] = true;
    auto solve = [&]() {
        int n, m;
        std::cin >> n;
        for (auto x : prime) {
            if (x >= n) {
                std::cout << -1 << ln;
                return;
            }
            if (!not_prime[n - x] && !not_prime[x]) {
                int tmp = 1;
                for (int i = 0; i < n; ++i) {
                    std::cout << tmp << ' ';
                    ((tmp += x - 1) %= n) += 1;
                }
                std::cout << ln;
                return;
            }
        }
    };

    while (_--) solve();
    std::cin >> _;
}
