/* Copyright 2025 Allergy
 * @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\5_18_VP\d.cpp
 * @date      2025/05/18 11:45:17
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
    auto solve = [&]() -> void {
        int n, m, p;
        std::cin >> n >> m >> p;
        std::vector<double> a(n);
        std::vector<double> b(m);
        std::vector<double> c(p);
        double suma = 0, sumb = 0, sumc = 0;
        for (auto &x : a) std::cin >> x, suma += x;
        for (auto &x : b) std::cin >> x, sumb += x;
        for (auto &x : c) std::cin >> x, sumc += x;
        double avr = (suma + sumb + sumc) / 3.0;
        // a->b a->c b->a b->c c->a c->b
        std::array<double, 6> ans{};
        // Step.1 all to a
        if (sumb > avr) ans[0] += sumb - avr;
        if (sumc > avr) ans[1] += sumc - avr;
        // Step.2 a to all
        if (sumb < avr) ans[2] += avr - sumb;
        if (sumc < avr) ans[4] += avr - sumc;

        for (int i = 0; i < 6; ++i) std::cout << std::fixed << std::setprecision(2) << ans[i] << ' ';
        std::cout << ln;
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
