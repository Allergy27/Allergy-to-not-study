// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\flashmen\prefix_sum\b.cpp
 * @date      2024/11/02 19:59:49
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
    vector<int> qaq(n + 1);
    for (int i = 0; i < n; ++i) qaq[i + 1] = qaq[i] + qwq[i];
    cin >> m;
    int ans = m / qaq[n] * n;  // 计算有几段，直接添加到答案中
    m %= qaq[n];               // 剩下的部分的大小
    // 这里我用的二分去找，实际O(n)的查询也能过
    ans += upper_bound(qaq.begin(), qaq.end(), m) - qaq.begin();
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
