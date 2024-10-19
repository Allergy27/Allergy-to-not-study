// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace NowCode\JML\G.cpp
 * @date      2024/10/16 13:51:09
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n;

    vector<pair<int, int>> a(n);

    for (auto &x : a) cin >> x.first >> x.second;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                if ((a[k].first - a[i].first) * (a[j].second - a[i].second) ==
                    (a[j].first - a[i].first) * (a[k].second - a[i].second)) {
                    cout << "Yes" << ln;
                    return;
                }
            }
        }
    }
    cout << "No" << ln;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
