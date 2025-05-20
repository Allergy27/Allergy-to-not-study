// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1021 div2\d.cpp
 * @date      2025/05/08 19:47:30
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
    const int MOD = 1e9 + 7;
    int n, m, k;
    std::cin >> n >> m >> k;
    UFSet uf(n * m);

    auto to = [&](int x, int y) { return (x - 1) * m + y; };

    std::vector<PII> qwq(k + 1);
    for (auto &[x, y] : qwq) std::cin >> x >> y;

    std::vector<int> cnt(n * m + 1), ring(n * m + 1);
    for (int i = 1; i <= k; ++i) {
        auto [x1, y1] = qwq[i - 1];
        auto [x2, y2] = qwq[i];
        if (std::abs(x1 - x2) + std::abs(y1 - y2) != 2) {
            std::cout << 0 << ln;
            return;
        }

        // 确定要连的边
        int u, v;
        if (std::abs(x1 - x2) == 1)  // 斜向
            u = to(x1, y2), v = to(x2, y1);
        else if (x1 == x2)
            u = to(x1, (y1 + y2) / 2), v = to(x1, (y1 + y2) / 2);
        else
            u = to((x1 + x2) / 2, y1), v = to((x1 + x2) / 2, y1);

        if (!uf.same(u, v)) {
            cnt[uf.find(u)] += cnt[uf.find(v)];  // 连通分量大小
            ring[uf.find(u)] |= ring[uf.find(v)];
            uf.merge(u, v);
        }
        ++cnt[uf.find(u)];
        if (u == v) ring[uf.find(u)] = 1;
    }
    int ans = 1;
    for (int i = 0; i <= n * m; ++i) {
        if (uf.find(i) != i) continue;
        int tmp = uf.size(i);
        if (tmp < cnt[i]) {  // 点小于边
            ans = 0;
            break;
        } else if (tmp == cnt[i]) {           // 点等于边
            if (!ring[i]) (ans *= 2) %= MOD;  // 没自环就*2
        } else {
            (ans *= tmp) %= MOD;  // 不然就乘法原理
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
