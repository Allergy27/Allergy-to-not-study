// Copyright 2024 Allergy
// email     Allergy527@gmail.com
// workspace CF\10.6contest\b.cpp
// date      2024/10/06 14:36:59
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
// #define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m, x;
    cin >> n >> m;
    vector<int> qwq(n + 2);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x <= n) qwq[x] += 1;
    }
    for (int i = 0; i <= n + 1; ++i) {
        if (i >= m && qwq[i - m] > 1) {
            qwq[i] += qwq[i - m] - 1;
            qwq[i - m] = 1;
        }
        if (qwq[i] == 0) {
            cout << i << '\n';
            return;
        }
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
