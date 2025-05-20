// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1024 div2\a.cpp
 * @date      2025/05/11 22:34:02
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
        int n, m, p, q;
        std::cin >> n >> m >> p >> q;
        judge(!(n / p * q != m && (n % p == 0)));
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
