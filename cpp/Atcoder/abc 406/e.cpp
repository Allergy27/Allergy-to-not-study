/* Copyright 2025 Allergy
 * @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\Atcoder\abc 406\e.cpp
 * @date      2025/05/18 15:24:15
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define judge(x) std::cout << ((x) ? "Yes\n" : "No\n")

using ll = int64_t;
using PII = std::pair<int, int>;
using PDD = std::pair<double, double>;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int _ = 1;
    std::cin >> _;
    const int N = 64;
    const int MOD = 998244353;
    std::vector c(N + 1, std::vector<int>(N + 1)), s(N + 1, std::vector<int>(N + 1));
    for (int i = 0; i <= N; ++i)
        for (int j = 0; j <= N; ++j) c[i][j] = 0, s[i][j] = 0;
    c[0][0] = 1;

    std::vector<int> pow(N + 1);
    pow[0] = 1;
    for (int i = 1; i <= N; ++i) pow[i] = (pow[i - 1] << 1) % MOD;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            (c[i + 1][j + 1] += c[i][j]) %= MOD;
            (s[i + 1][j + 1] += s[i][j]) %= MOD;
            (s[i + 1][j + 1] += 1LL * c[i][j] * pow[i] % MOD) %= MOD;
            (s[i + 1][j] += s[i][j]) %= MOD;
            (c[i + 1][j] += c[i][j]) %= MOD;
        }
    }

    auto solve = [&]() -> void {
        ll n, m;
        std::cin >> n >> m;
        std::vector<int> qwq(N);
        for (int i = 0; i < N; ++i) {
            qwq[i] = n & 1;
            n >>= 1;
        }
        int cur = 0;
        int tmp = 0;
        int ans = 0;
        for (int i = N - 1; i >= 0; --i) {
            if (qwq[i] == 1) {
                if (cur <= m) {
                    (ans += s[i][m - cur]) %= MOD;
                    (ans += 1LL * tmp * c[i][m - cur] % MOD) %= MOD;
                }
                ++cur;
                (tmp += pow[i]) %= MOD;
            }
        }
        if (cur == m) (ans += tmp) %= MOD;
        std::cout << ans << ln;
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
