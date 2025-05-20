// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\Atcoder\abc 405\e.cpp
 * @date      2025/05/10 20:41:39
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
    // std::cin >> _;

    auto solve = [&]() -> void {
        const int MOD = 998244353;

        std::vector<int> fac, inv_fac;
        int max_n = 1;

        fac = {1};
        inv_fac = {1};
        max_n = 0;

        auto preprocess = [&](int n) -> void {
            if (n <= max_n) return;
            fac.resize(n + 1);
            inv_fac.resize(n + 1);
            for (int i = max_n + 1; i <= n; ++i) fac[i] = 1LL * fac[i - 1] * i % MOD;
            inv_fac[n] = 1;
            int base = fac[n], power = MOD - 2;
            while (power) {
                if (power & 1) inv_fac[n] = 1LL * inv_fac[n] * base % MOD;
                base = 1LL * base * base % MOD;
                power >>= 1;
            }
            for (int i = n - 1; i > max_n; --i) inv_fac[i] = 1LL * inv_fac[i + 1] * (i + 1) % MOD;
            max_n = n;
        };

        auto comb = [&](int n, int k) -> int {
            if (k < 0 || k > n) return 0;
            preprocess(n);  // 确保已经预处理到n
            return 1LL * fac[n] * inv_fac[k] % MOD * inv_fac[n - k] % MOD;
        };

        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        int ans = 0;
        for (int i = 0; i <= b; ++i) {  // 多出来几个 B ?
            int m = b - i;
            ll ab = comb(a + m - 1, a - 1);
            ll bcd = comb(c + d + i, c);
            (ans += static_cast<int>(ab * bcd % MOD)) %= MOD;
        }
        std::cout << ans << ln;
    };

    while (_--) solve();
    std::cin >> _;
    return 0;
}
