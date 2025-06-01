// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace CF\10.14contest\c.cpp
 * @date      2024/10/14 22:25:32
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
    cin >> n >> m;
    vector<int> qwq(n);
    for (auto &x : qwq) cin >> x;
    sort(qwq.begin(), qwq.end());
    int l = 0, r = 0;
    int l_ans = qwq[0], r_ans = qwq[0];
    int ans = 1;
    while (r < n) {
        if (++r == n) break;
        if (qwq[r] > r_ans + 1) {
            ans = max(ans, r - l);
            l = r;
            l_ans = qwq[r];
        }
        r_ans = qwq[r];
        while (r_ans - l_ans + 1 > m) {
            l_ans = qwq[++l];
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}