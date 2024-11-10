// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\week\c.cpp
 * @date      2024/11/10 19:25:45
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
    auto cot = [](int x) -> int {
        if (x == 0) return 1;
        int ans = 0;
        while (x) {
            ans++;
            x /= 10;
        }
        return ans;
    };
    int len = cot(m);
    int al = n - 2 - len;
    if (al <= 0) {
        cout << 0 << ln;
        return;
    }
    int ans = 0;
    for (int i = 0; i <= m; ++i) {
        // cout << cot(i) << cot(m - i) << len << 2 << endl;
        if (cot(i) + cot(m - i) + len + 2 == n) {
            ans++;
        }
    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
