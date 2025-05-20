/* Copyright 2025 Allergy
 * @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\25_5_17\Geshin_impart_8880.cpp
 * @date      2025/05/17 16:23:17
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
        int n, m;
        std::cin >> n;
        std::vector<int> qwq(n);
        for (auto &x : qwq) std::cin >> x;
        if ((n & 1) == 0) {
            std::cout << -1 << ln;
            return;
        }

        std::array<std::vector<int>, 2> ans;
        ans[0].resize(n), ans[1].resize(n);
        for (int i = 0; i < n; ++i) {
            ans[0][(2 * i + 1) % n] = i;
            ans[1][(2 * i + 1) % n] = (i + 1) % n;
        }
        for (auto x : qwq) std::cout << ans[0][x] << ' ';
        std::cout << ln;
        for (auto x : qwq) std::cout << ans[1][x] << ' ';
        std::cout << ln;
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
