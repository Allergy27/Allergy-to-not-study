// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\25_5_15\9_3_Convex_3829.cpp
 * @date      2025/05/15 16:17:36
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
        auto rotate = [](PDD ori, double rad) -> PDD {
            double cos = std::cos(rad);
            double sin = std::sin(rad);

            PDD res;
            res.first = ori.first * cos - ori.second * sin;
            res.second = ori.first * sin + ori.second * cos;
            return res;
        };
        int n;
        std::cin >> n;
        double a, b, l;
        std::cin >> a >> b >> l;
        const std::array<int, 5> WAY = {-1, -1, 1, 1, -1};

        a -= 2.0 * l, b -= 2.0 * l;
        double phi = std::atan2(a, b);
        double tmp = sqrt(a * a + b * b) / 2.0;
        std::vector<PDD> qwq;

        for (int i = 0; i < n; ++i) {
            double x, y, r;
            std::cin >> x >> y >> r;
            double dx1 = std::cos(r + phi) * tmp;
            double dy1 = std::sin(r + phi) * tmp;

            qwq.push_back({x + dx1, y + dy1});
            qwq.push_back({x - dx1, y - dy1});

            double dx2 = std::cos(r - phi) * tmp;
            double dy2 = std::sin(r - phi) * tmp;

            qwq.push_back({x + dx2, y + dy2});
            qwq.push_back({x - dx2, y - dy2});
        }
        auto cal = [](std::vector<PDD> &p) -> double {
            int n = p.size(), k = 0;
            if (n <= 1) return 0;

            sort(p.begin(), p.end());
            std::vector<PDD> h(2 * n);

            auto cross = [](PDD a, PDD b) { return a.first * b.second - a.second * b.first; };
            auto sub = [](PDD a, PDD b) { return PDD{a.first - b.first, a.second - b.second}; };

            for (int i = 0; i < n; h[k++] = p[i++])
                while (k >= 2 && cross(sub(h[k - 1], h[k - 2]), sub(p[i], h[k - 1])) <= 0) --k;

            for (int i = n - 2, t = k + 1; i >= 0; h[k++] = p[i--])
                while (k >= t && cross(sub(h[k - 1], h[k - 2]), sub(p[i], h[k - 1])) <= 0) --k;

            double ans = 0;
            for (int i = 0; i < k - 1; ++i) {
                double dx = h[i + 1].first - h[i].first;
                double dy = h[i + 1].second - h[i].second;
                ans += sqrt(dx * dx + dy * dy);
            }

            return ans;
        };

        double ans = cal(qwq);
        ans += l * 3.141592653589793 * 2.0;
        std::cout << std::fixed << std::setprecision(2) << ans << ln;
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
