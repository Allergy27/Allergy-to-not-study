// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\winter_camp\Day 5\merge.cpp
 * @date      2025/01/17 19:26:13
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

struct UFSet {
    std::vector<int> fa, sz;
    std::vector<std::set<std::pair<int, int>>> s;
    UFSet(int n) : fa(n + 1), sz(n + 1, 1), s(n + 1) {  // NOLINT
        iota(fa.begin(), fa.end(), 0);
    }
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
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (s[x].size() < s[y].size()) std::swap(x, y);
        for (auto t : s[y]) s[x].insert(t);
        sz[x] += sz[y];
        fa[y] = x;
        return true;
    }
    int size(int x) {
        return sz[find(x)];
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
