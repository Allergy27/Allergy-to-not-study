// Copyright 2024 Allergy
// email     Allergy527@gmail.com
// workspace CF\9.29contest\d.cpp
// date      2024/09/30 00:22:59
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

struct UFSet {
    vector<int> fa;
    UFSet(int n) : fa(n + 1) {  // NOLINT
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

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        fa[y] = x;
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    UFSet qwq(n);
    for (int i = 0; i < m; ++i) {
        int a, d, k;
        cin >> a >> d >> k;
        for (int j = 1; j <= k; ++j) qwq.merge(a, a + j * d);
    }
    set<int> qvq;
    for (auto x : qwq.fa) qvq.insert(qwq.find(x));
    cout << qvq.size() - 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
