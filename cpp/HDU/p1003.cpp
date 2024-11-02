// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\HDU\p1003.cpp
 * @date      2024/10/30 12:01:53
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
    int t;
    cin >> t;
    for (int c = 1; c <= t; ++c) {
        int n;
        cin >> n;
        vector<int> qwq(n);
        for (auto &x : qwq) cin >> x;
        int l = 0, r = 1;
        vector<int> ans = {qwq[0], 1, 1};
        int tmp = qwq[0];
        while (r < n) {
            if (ans[0] < 0 && qwq[r] > ans[0]) {
                l = r;
                tmp = qwq[r];
                ans = {qwq[r++], r, r};
            } else if (tmp + qwq[r] < 0) {
                tmp = 0;
                l = ++r;
            } else {
                tmp += qwq[r++];
                if (ans[0] < tmp) {
                    ans = {tmp, l + 1, r};
                }
            }
        }
        cout << "Case " << c << ':' << ln;
        cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ln;
        if (c != t) cout << ln;
    }
}
signed main() {
    solve();
    return 0;
}
