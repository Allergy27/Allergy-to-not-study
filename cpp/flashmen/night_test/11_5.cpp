// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\flashmen\night_test\11_5.cpp
 * @date      2024/11/05 18:38:00
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
    vector<int> qwq(n);
    for (auto &x : qwq) cin >> x;
    sort(qwq.begin(), qwq.end());
    vector<int> qaq;
    for (int i = 1; i < n; ++i) qaq.push_back(qwq[i] + qwq[i - 1]);
    int ans = inf;
    for (int i = n - 1; i >= 0; --i)
        ans = min(ans, upper_bound(qaq.begin(), qaq.end(), qwq[i]) - qaq.begin() + n - 1 - i);
    cout << ans << ln;
}

signed main() {
    // ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
