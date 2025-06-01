// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf edu 177\d.cpp
 * @date      2025/04/03 23:53:58
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
    const int MAX = 5e5 + 27;
    const int MOD = 998244353;
    std::vector<int> fact(MAX), inv_fact(MAX);

    auto qpow = [](int a, int b) {
        int ans = 1;
        while (b > 0) {
            if (b & 1) ans = ans * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return ans;
    };

    fact[0] = 1;
    for (int i = 1; i < MAX; ++i) fact[i] = fact[i - 1] * i % MOD;
    inv_fact[MAX - 1] = qpow(fact[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; --i) inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;

    while (t--) {
        int n = 0, m = 26;
        std::vector<int> qwq(m);
        for (auto &x : qwq) {
            std::cin >> x;
            n += x;
        }
        // 0 1 2 3 4 -> 5 -> even = (5+1)/2
        int even_pos = (n + 1) / 2, odd_pos = n / 2;
        std::vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 0; i < m; ++i) {
            if (qwq[i] == 0) continue;
            for (int j = n; j >= qwq[i]; --j) dp[j] = (dp[j] + dp[j - qwq[i]]) % MOD;
        }
        int ans = dp[odd_pos];
        for (int i = 0; i < m; i++) ans = ans * inv_fact[qwq[i]] % MOD;
        ans = ans * fact[odd_pos] % MOD;
        ans = ans * fact[even_pos] % MOD;
        std::cout << ans << ln;
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
