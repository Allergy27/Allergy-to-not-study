/* Copyright 2025 Allergy
 * @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\Atcoder\abc 406\d.cpp
 * @date      2025/05/17 20:58:38
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
        int n, m, k;
        std::cin >> n >> m >> k;
        std::vector<std::set<int>> h(n), w(m);

        for (int i = 0; i < k; ++i) {
            int x, y;
            std::cin >> x >> y;
            --x, --y;
            h[x].insert(y);
            w[y].insert(x);
        }
        int q;
        std::cin >> q;
        for (int i = 0; i < q; ++i) {
            int op, x;
            std::cin >> op >> x;
            x -= 1;
            if (op == 1) {
                std::cout << h[x].size() << ln;
                for (auto p : h[x]) w[p].erase(x);
                h[x].clear();
            } else {
                std::cout << w[x].size() << ln;
                for (auto p : w[x]) h[p].erase(x);
                w[x].clear();
            }
        }
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
