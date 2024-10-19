// Copyright 2024 Allergy
// email     Allergy527@gmail.com
// workspace CF\10.6contest\c1.cpp
// date      2024/10/06 15:36:52
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
// #define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> qwq(n);
    vector<int> qaq(m);
    unordered_map<int, int> qvq;
    for (auto &x : qwq) cin >> x;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        if (qvq.find(x) == qvq.end()) qvq[x] = i;
    }
    for (int i = 0; i < n; ++i)
        qwq[i] = qvq[qwq[i]];
    vector<int> ans = qwq;
    sort(ans.begin(), ans.end());
    if (ans != qwq) {
        cout << "TIDAK\n";
    } else {
        cout << "YA\n";
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
