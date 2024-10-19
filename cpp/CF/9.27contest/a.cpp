// Copyright 2024 Allergy
// email     Allergy527@gmail.com
// workspace CF\9.27contest\a.cpp
// date      2024/09/27 21:31:43
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
    int max_n = 0, max_i = 0;
    for (int i = 0; i < n; i++)
        if (qwq[i] > max_n || qwq[i] == max_n && !(i & 1))
            max_n = qwq[i], max_i = i;
    cout << max_n + n / 2 + (n & 1 && !(max_i & 1)) << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
