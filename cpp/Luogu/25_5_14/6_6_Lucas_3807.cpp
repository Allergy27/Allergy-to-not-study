// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\25_5_14\6_6_Lucas_3807.cpp
 * @date      2025/05/14 18:25:53
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define PII std::pair<int, int>
#define judge(x) std::cout << ((x) ? "Yes\n" : "No\n")

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int _ = 1;
    std::cin >> _;

    auto solve = [&]() -> void {
        int n, m, p;
        std::cin >> n >> m >> p;

        std::vector<ll> fac(p + 1);
        fac[0] = 1;
        for (int i = 1; i <= p; ++i) fac[i] = (fac[i - 1] * i) % p;

        auto qpow = [](ll a, ll b, ll p) -> ll {
            ll ans = 1;
            a %= p;
            while (b) {
                if (b & 1) (ans *= a) %= p;
                (a *= a) %= p, b >>= 1;
            }
            return ans;
        };

        auto comb = [&](ll n, ll k, ll p) -> ll {
            return (k > n) ? 0 : ((fac[n] * qpow(fac[n - k], p - 2, p) % p) * qpow(fac[k], p - 2, p));
        };

        auto lucas = [&](auto &&lucas, ll n, ll k, ll p) -> ll {
            return (k == 0) ? 1 : comb(n % p, k % p, p) * lucas(lucas, n / p, k / p, p) % p;
        };

        std::cout << lucas(lucas, n + m, n, p) << ln;
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
