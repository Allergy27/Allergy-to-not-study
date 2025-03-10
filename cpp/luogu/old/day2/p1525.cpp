// Copyright 2024 Allergy
// email     Allergy527@gmail.com
// workspace luogu\day2\p1525.cpp
// date      2024/09/23 21:19:38
#include <bits/stdc++.h>
// #define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

struct Node {
    int x, y, w;
    bool operator<(const Node &rhs) const {
        return w > rhs.w;
    }
};

struct UFSet {
    vector<int> fa, rel;
    UFSet(int n) : fa(n + 1), rel(n + 1) {  // NOLINT
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        if (fa[x] == x) return x;
        int temp = find(fa[x]);
        rel[x] = rel[x] ^ rel[fa[x]];
        return fa[x] = temp;
    }
    void merge(int x, int y, int rootx, int rooty) {
        int relation = (rel[x] + rel[y] + 1) % 2;
        fa[rooty] = rootx;
        rel[rooty] = relation;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Node> qwq(m);
    for (auto &[x, y, w] : qwq) cin >> x >> y >> w;
    sort(qwq.begin(), qwq.end());
    UFSet qvq(n);
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int x = qwq[i].x, y = qwq[i].y, w = qwq[i].w;
        int rootx = qvq.find(x), rooty = qvq.find(y);
        if (rootx != rooty) {
            qvq.merge(x, y, rootx, rooty);
        } else {
            int relation = qvq.rel[x] ^ qvq.rel[y];
            if (relation == 0) {
                ans = w;
                break;
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
