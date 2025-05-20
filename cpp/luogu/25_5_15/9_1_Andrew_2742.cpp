// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\25_5_15\9_1_Andrew_2742.cpp
 * @date      2025/05/15 11:21:15
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
        std::vector<PDD> qwq(n);
        for (auto &[x, y] : qwq) std::cin >> x >> y;
        std::sort(qwq.begin(), qwq.end());
        auto andrew = [](std::vector<PDD> &p) -> std::vector<PDD> {
            int n = p.size(), k = 0;
            if (n <= 1) return p;

            sort(p.begin(), p.end());
            std::vector<PDD> h(2 * n);

            auto cross = [](PDD a, PDD b) { return a.first * b.second - a.second * b.first; };
            auto sub = [](PDD a, PDD b) { return PDD{a.first - b.first, a.second - b.second}; };

            for (int i = 0; i < n; h[k++] = p[i++])
                while (k >= 2 && cross(sub(h[k - 1], h[k - 2]), sub(p[i], h[k - 1])) <= 0) --k;

            for (int i = n - 2, t = k + 1; i >= 0; h[k++] = p[i--])
                while (k >= t && cross(sub(h[k - 1], h[k - 2]), sub(p[i], h[k - 1])) <= 0) --k;

            h.resize(k - 1);

            return h;
        };

        std::vector<PDD> tmp = andrew(qwq);
        int len = tmp.size();
        double ans = 0;
        for (int i = 1; i <= len; ++i) {
            double dx = tmp[i % len].first - tmp[i - 1].first;
            double dy = tmp[i % len].second - tmp[i - 1].second;
            ans += sqrt(dx * dx + dy * dy);
        }
        std::cout << std::fixed << std::setprecision(2) << ans << ln;
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
