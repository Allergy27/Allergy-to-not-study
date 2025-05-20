/* Copyright 2025 Allergy
 * @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\5_18_VP\e.cpp
 * @date      2025/05/18 10:25:27
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

    const int MOD = 998244353;

    std::vector<int> qwq(65);
    qwq[0] = 1;
    for (int i = 1; i <= 64; ++i) qwq[i] = (1LL * qwq[i - 1] * 3) % MOD;

    auto solve = [&]() -> void {
        ll n;
        std::cin >> n;
        int ans = 0;
        std::vector<int> tmp;
        int up = 0;
        ++n;
        while (n > 0) {
            if (n & 1) tmp.emplace_back(up);
            n >>= 1;
            ++up;
        }
        int len = tmp.size() - 1;
        ll cur = 1;
        for (int i = len; i >= 0; --i) {
            (ans += 1LL * (qwq[tmp[i]]) * cur % MOD) %= MOD;
            cur = (cur << 1) % MOD;
        }

        std::cout << ans << ln;
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
