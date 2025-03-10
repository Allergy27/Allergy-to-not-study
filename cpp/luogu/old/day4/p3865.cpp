// Copyright 2024 Allergy
// email     Allergy527@gmail.com
// workspace luogu\day4\p3865.cpp
// date      2024/09/26 22:02:04
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
// #define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

struct ST {
    vector<vector<int>> st;
    vector<int> lg;
    ST(vector<int> a, int n) : st(n + 1, vector<int>(log(n) / log(2) + 1)), lg(n + 1) {  // NOLINT
        for (int i = 1; i <= n; i++) st[i][0] = a[i];
        for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
        int t = lg[n] + 1;
        for (int j = 1; j < t; ++j) {
            ll d = n - (1 << j) + 1;
            for (int i = 1; i <= d; ++i)
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    ll query(ll l, ll r) {
        ll k = lg[r - l + 1];
        return max(st[l][k], st[r - (1 << k) + 1][k]);
    }
};

void solve() {
    int n, m, l, r;
    cin >> n >> m;
    vector<int> qwq(n + 1);
    for (int i = 1; i <= n; ++i) cin >> qwq[i];
    ST qvq(qwq, n);
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        cout << qvq.query(l, r) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
