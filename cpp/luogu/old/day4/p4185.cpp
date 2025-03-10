// Copyright 2024 Allergy
// email     Allergy527@gmail.com
// workspace luogu\day4\p4185.cpp
// date      2024/09/26 20:18:04
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
// #define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

struct video {
    int p, q, r;
    bool operator>(const video &rhs) const {
        return r > rhs.r;
    }
};

struct sch {
    int k, v, n;
    bool operator>(const sch &rhs) const {
        return k > rhs.k;
    }
};

struct UFSet {
    vector<int> fa, sz;
    vector<set<pair<int, int>>> s;
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
        if (s[x].size() < s[y].size()) swap(x, y);
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
    int n, m, k = 0;
    cin >> n >> m;
    vector<video> query(n - 1);
    UFSet qwq(n);
    vector<sch> s(m);
    vector<int> ans(m);
    for (auto &[x, y, z] : query) cin >> x >> y >> z;
    sort(query.begin(), query.end(), greater<video>());
    for (int i = 0; i < m; ++i) {
        cin >> s[i].k >> s[i].v;
        s[i].n = i;
    }
    sort(s.begin(), s.end(), greater<sch>());
    for (auto x : s) {
        while (k < n - 1 && query[k].r >= x.k) qwq.merge(query[k].p, query[k].q), k++;
        ans[x.n] = qwq.size(x.v) - 1;
    }
    for (auto x : ans) cout << x << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
