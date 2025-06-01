/* Copyright 2025 Allergy
 * @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\25_5_16\2_4_Qpow_1226.cpp
 * @date      2025/05/16 19:13:46
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
    // std::cin >> _;

    auto solve = [&]() -> void {
        int a, b, p;
        std::cin >> a >> b >> p;
        auto qpow = [](int a, int b, int p) -> int {
            int ans = 1;
            for (; b; b >>= 1) {
                if (b & 1) ans = 1LL * ans * a % p;
                a = 1LL * a * a % p;
            }
            return ans;
        };
        std::cout << a << '^' << b << " mod " << p << '=' << qpow(a, b, p) << ln;
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
