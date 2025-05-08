// Copyright 2024 Allergy
// email     Allergy527@gmail.com
// workspace CF\10.6contest\a.cpp
// date      2024/10/06 13:53:15
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
// #define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n;
    vector<int> qwq(n);
    for (auto &x : qwq) cin >> x;
    sort(qwq.begin(), qwq.end());
    int ans = qwq[0];
    for (int i = 1; i < n; ++i)
        ans = floor((ans + qwq[i]) / 2);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
