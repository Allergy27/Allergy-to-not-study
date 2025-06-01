/* Copyright 2025 Allergy
 * @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\25_5_17\Genshin_impart_8881.cpp
 * @date      2025/05/17 17:21:48
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

    struct UFSet {
        std::vector<int> fa, sz;
        std::vector<std::set<std::pair<int, int>>> s;
        explicit UFSet(int n) : fa(n + 1), sz(n + 1, 1), s(n + 1) { iota(fa.begin(), fa.end(), 0); }
        int find(int x) {
            int root = x, t;
            while (root != fa[root]) root = fa[root];
            while (x != fa[x]) {
                t = x;
                x = fa[x];
                fa[t] = root;
            }
            return root;
        }
        bool same(int x, int y) { return find(x) == find(y); }
        bool merge(int x, int y) {
            x = find(x), y = find(y);
            if (x == y) return false;
            if (s[x].size() < s[y].size()) std::swap(x, y);
            for (auto t : s[y]) s[x].insert(t);
            sz[x] += sz[y];
            fa[y] = x;
            return true;
        }
        int size(int x) { return sz[find(x)]; }
    };

    auto solve = [&]() -> void {
        int n, m;
        std::cin >> n >> m;
        UFSet qwq(n);
        std::string s = "1.000";
        for (int i = 0; i < m; ++i) {
            int u, v;
            std::cin >> u >> v;
            if (!qwq.merge(u, v) && qwq.find(u) == qwq.find(1)) s = "0.000";
        }
        std::cout << s << ln;
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
