// Copyright 2024 Allergy
// email     Allergy527@gmail.com
// workspace luogu\day3\p9421.cpp
// date      2024/09/24 23:47:01
#include <bits/stdc++.h>
// #define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m, ans = 0, res_a = 0, res_b = 0;
    cin >> n;
    map<int, int> qwq;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++qwq[x];
    }
    for (auto [x, y] : qwq)
        y > 1 ? res_a += y - 2 : res_b += 1;
    if (res_a >= res_b) {
        ans += res_b;
        res_a -= res_b;
        res_b = 0;
    } else {
        ans += res_a;
        res_b -= res_a;
        res_a = 0;
    }

    cout << ans + res_a + res_b / 2 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
