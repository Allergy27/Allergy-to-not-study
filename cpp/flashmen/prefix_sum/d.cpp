// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\flashmen\prefix_sum\d.cpp
 * @date      2024/11/02 21:06:32
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
    vector<int> qaq(n + 1);  // 前缀和
    for (int i = 1; i <= n; ++i) qaq[i] = qaq[i - 1] + qwq[i - 1];
    int tmp = 0;  // 记录每一段长度
    for (int i = 0; i < m; ++i) tmp += qwq[i] * (i + 1);
    int ans = tmp;
    for (int i = m; i < n; ++i) {
        tmp -= qaq[i + 1] - qaq[i - m] - qwq[i] * (m + 1);
        ans = max(ans, tmp);  // 更新最大值
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
