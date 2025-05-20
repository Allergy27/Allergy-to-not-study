/* Copyright 2025 Allergy
 * @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\Atcoder\abc 406\c.cpp
 * @date      2025/05/17 20:21:31
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define judge(x) std::cout << ((x) ? "Yes\n" : "No\n")

using ll = int64_t;
using PLL = std::pair<ll, ll>;
using PII = std::pair<int, int>;
using PDD = std::pair<double, double>;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int _ = 1;
    // std::cin >> _;

    auto solve = [&]() -> void {
        int n;
        std::cin >> n;
        std::vector<int> qwq(n);
        for (auto &x : qwq) std::cin >> x;
        std::vector<int> ck;
        for (int i = 1; i < n; ++i) ck.emplace_back(qwq[i] > qwq[i - 1]);
        std::vector<PLL> tmp;

        tmp.push_back({ck[0], 1});
        for (int i = 1; i < n - 1; ++i) {
            if (ck[i] == tmp.back().first)
                tmp.back().second += 1;
            else
                tmp.push_back({ck[i], 1});
        }
        int len = tmp.size();
        ll ans = 0;
        int st = tmp[0].first == 0 ? 3 : 2;
        for (int i = st; i < len; i += 2) ans += tmp[i].second * tmp[i - 2].second;
        std::cout << ans << ln;
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
