// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\flashmen\night_test\11_7_a.cpp
 * @date      2024/11/07 20:47:57
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> qwq(m);
    for (auto &x : qwq) cin >> x;
    sort(qwq.begin(), qwq.end());
    while (q--) {
        int pos;  // David 的位置
        cin >> pos;
        int r = upper_bound(qwq.begin(), qwq.end(), pos) - qwq.begin();
        if (r == 0)
            cout << qwq[0] - 1 << '\n';
        else if (r == m)
            cout << n - qwq[m - 1] << '\n';
        else
            cout << (qwq[r] - qwq[r - 1]) / 2 << '\n';
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
