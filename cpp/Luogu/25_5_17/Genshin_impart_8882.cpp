/* Copyright 2025 Allergy
 * @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\25_5_17\Genshin_impart_8882.cpp
 * @date      2025/05/17 18:25:28
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
        std::vector<int> op(n - 1);
        for (auto &x : op) std::cin >> x;
        std::cin >> m;
        std::vector<std::unordered_set<int>> qwq(n + m);
        for (int i = 1; i < n; ++i) {
            qwq[i].insert(op[i - 1] - 1);
            qwq[op[i - 1] - 1].insert(i);
        }
        int root = 0;
        auto f = [&](int i) -> bool { return qwq[i].size() == (i != root); };
        int ans = 0;
        for (int i = 1; i < n; ++i) ans += qwq[i].size() == 1;
        std::cout << ans << ln;
        for (int i = 0; i < m; ++i) {
            std::string s;
            int x;
            std::cin >> s >> x;
            --x;
            if (s == "Add") {
                if (!f(x)) ++ans;
                qwq[x].insert(n + i);
                qwq[n + i].insert(x);
            } else if (s == "Del") {
                qwq[*qwq[x].begin()].erase(x);
                if (!f(*qwq[x].begin())) --ans;
            } else {
                int y = root;
                root = -1;
                if (f(x) && !f(y)) --ans;
                if (!f(x) && f(y)) ++ans;
                root = x;
            }
            std::cout << ans << ln;
        }
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
