// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\StarryCoding\p149.cpp
 * @date      2024/12/03 16:38:34
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
    vector<int> pre(n), suf(n);

    pre[0] = qwq[0];
    for (int i = 1; i < n; ++i) pre[i] = __gcd(pre[i - 1], qwq[i]);

    suf[n - 1] = qwq[n - 1];
    for (int i = n - 2; i >= 0; --i) suf[i] = __gcd(suf[i + 1], qwq[i]);
    int ans = max(pre[n - 2], suf[1]);
    for (int i = 1; i < n - 1; ++i)
        ans = max(ans, __gcd(pre[i - 1], suf[i + 1]));

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
