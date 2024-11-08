// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\flashmen\night_test\11_7.cpp
 * @date      2024/11/07 18:51:26
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
    int n, k, q;
    cin >> n >> k >> q;
    // 二维数组
    vector<vector<int>> qwq(k, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < k; ++j) {
            cin >> qwq[j][i];
            // 直接在传入时完成转置
            if (i > 0) qwq[j][i] |= qwq[j][i - 1];
        }
    for (int _ = 0; _ < q; ++_) {
        int m;
        cin >> m;
        int l = 0;
        int r = n;
        for (int i = 0; i < m; ++i) {
            int f, v;
            char c;
            cin >> f >> c >> v;
            if (c == '<') {
                r = min(r, lower_bound(qwq[f - 1].begin(), qwq[f - 1].end(), v) - qwq[f - 1].begin());
            } else {
                l = max(l, upper_bound(qwq[f - 1].begin(), qwq[f - 1].end(), v) - qwq[f - 1].begin());
            }
        }
        if (l >= r)
            cout << -1 << ln;
        else
            cout << l + 1 << ln;
    }
}

signed main() {
    // ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
