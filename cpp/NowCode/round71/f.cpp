// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round71\e.cpp
 * @date      2024/12/08 20:29:17
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t
#define double long double

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

const int mod = 1000000007;
int qpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int C(int a, int b) {
    int ans = 1;
    for (int i = a; i >= a - b + 1; i--) ans = ans * i % mod;
    for (int j = 1; j <= b; j++) ans = ans * qpow(j, mod - 2) % mod;
    return ans;
}

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> a(n);
    for (auto &x : a) std::cin >> x;
    int ans = 0;
    int sum = qpow(2, k);
    for (auto num : a) {
        int x = sum;
        for (int j = 0; j <= std::min(35LL, k); j++) {
            int g = C(k, j);
            ans += num * g % mod;
            ans %= mod;
            x = (x - g + mod) % mod;
            if (!(num & m)) break;
            num = num + (num & m);
        }
        ans += num * x % mod;
        ans %= mod;
    }
    std::cout << ans * qpow(qpow(2, k), mod - 2) % mod;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
