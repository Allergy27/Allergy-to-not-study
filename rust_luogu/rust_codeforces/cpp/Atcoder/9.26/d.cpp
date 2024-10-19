// Copyright 2024 Allergy
// email     Allergy527@gmail.com
// workspace Atcoder\9.26\d.cpp
// date      2024/09/28 20:47:35
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
// #define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

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
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
