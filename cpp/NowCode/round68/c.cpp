// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round68\c.cpp
 * @date      2024/11/26 18:30:56
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
    set<int> a, b, c;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        a.insert(m);
        c.insert(m);
    }
    for (int i = 0; i < n; ++i) {
        cin >> m;
        b.insert(m);
        c.insert(m);
    }
    cout << max(n - c.size() / 2, n - min(a.size(), b.size())) << ln;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
