/*Copyright 2024 Allergy
 *@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace luogu\day2\p3958.cpp
 *@date      2024/09/22 13:26:31
 */
#include <bits/stdc++.h>
#define int int64_t
using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

struct UFSet {
    vector<int> fa, sz;
    vector<set<pair<int, int>>> s;
    explicit UFSet(int n) : fa(n + 1), sz(n + 1, 1), s(n + 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        int ans = x, t;
        while (ans != fa[ans]) ans = fa[ans];
        while (x != fa[x]) {
            t = x;
            x = fa[x];
            fa[t] = ans;
        }
        return ans;
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
    int n, m, h, r;
    cin >> n >> h >> r;
    UFSet qwq(n + 1);
    vector<tuple<int, int, int>> graph(n);
    for (auto &[x, y, z] : graph)
        cin >> x >> y >> z;
    auto check = [&](tuple<int, int, int> a, tuple<int, int, int> b) -> int {
        return pow(get<0>(a) - get<0>(b), 2) + pow(get<1>(a) - get<1>(b), 2) + pow(get<2>(a) - get<2>(b), 2);
    };

    for (int i = 1; i <= n; ++i) {
        if (get<2>(graph[i - 1]) <= r)
            qwq.merge(i, 0);
        if (get<2>(graph[i - 1]) >= h - r)
            qwq.merge(i, n + 1);
        for (int j = 1; j < i; ++j) {
            if (check(graph[i - 1], graph[j - 1]) <= 4 * r * r) {
                qwq.merge(i, j);
            }
        }
    }
    if (qwq.same(0, n + 1))
        cout << "Yes\n";
    else
        cout << "No\n";
}

signed main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
