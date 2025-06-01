// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 998 div3\f.cpp
 * @date      2025/01/20 00:04:05
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 100005;
std::vector<int> fact(MAXN), invFact(MAXN);

// 快速幂计算 a^b % MOD
int power(int a, int b, int mod) {
    int res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

// 计算 n! % MOD
int factorial(int n, int mod) {
    int res = 1;
    for (int i = 2; i <= n; ++i) {
        res = (res * i) % mod;
    }
    return res;
}

// 计算组合数 C(n, k) % MOD
int comb(int n, int k, int mod) {
    if (k > n || k < 0) return 0;
    int num = factorial(n, mod);
    int denom = (factorial(k, mod) * factorial(n - k, mod)) % mod;
    return (num * power(denom, mod - 2, mod)) % mod;
}

void solve() {
    const int MOD = 998244353;
    int k, n;
    std::cin >> k >> n;
    std::vector<int> ans(k + 1, 0);

    auto getDiv = [](int x) -> std::vector<int> {
        std::vector<int> div;
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                div.push_back(i);
                if (i != x / i) div.push_back(x / i);
            }
        }
        return div;
    };

    for (int x = 1; x <= k; x++) {
        std::vector<int> divs = getDiv(x);
        for (auto div : divs) {
            ans[x - 1] += comb(n, div, MOD) % MOD;
        }
    }

    for (int i = 0; i < k; i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
