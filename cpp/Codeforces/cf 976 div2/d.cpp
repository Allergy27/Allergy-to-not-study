// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 976 div2\d.cpp
 * @date      2025/04/15 19:13:37
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t
#define PII std::pair<int, int>

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

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

void solve() {
    int n, m;
    std::cin >> n >> m;
    UFSet uf(n);
    const int M = 11;
    std::vector<std::vector<std::vector<PII>>> op(M, std::vector<std::vector<PII>>(M));

    for (int i = 0; i < m; ++i) {
        int a, d, k;
        std::cin >> a >> d >> k;
        if (k == 0) continue;
        --a;
        op[d][a % d].push_back({a / d, a / d + k - 1});
    }

    int ans = n;
    for (int d = 1; d < M; ++d) {
        for (int r = 0; r < d; ++r) {
            auto &list = op[d][r];
            if (list.empty()) continue;
            std::sort(list.begin(), list.end());
            int end = -1;
            for (auto [x, y] : list) {
                for (int i = std::max(end + 1, x); i <= y; ++i) ans -= uf.merge(i * d + r, (i + 1) * d + r);
                end = std::max(end, y);
            }
        }
    }
    std::cout << ans << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
