// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\flashmen\prefix_sum\e.cpp
 * @date      2024/11/02 18:20:57
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
    // Step 1. O(n)预处理
    vector<int> qaq(n + 1);   // 前缀和
    vector<int> h(n + 1);     // 纵向前缀和
    vector<int> w(n + 1);     // 横向前缀和
    vector<int> tsum(n + 1);  // 前缀和总和的前缀和
    for (int i = 1; i <= n; ++i) qaq[i] = qaq[i - 1] + qwq[i - 1];
    for (int i = 1; i <= n; ++i) h[i] = h[i - 1] + qaq[i];
    for (int i = 1; i <= n; ++i) w[i] = w[i - 1] + qwq[i - 1] * (n - i + 1);
    auto t = [&](int l, int r) -> int {
        return h[r] - w[l - 1] + (n - r) * qaq[l - 1];
    };
    for (int i = 1; i <= n; ++i) tsum[i] = tsum[i - 1] + t(i, n);
    // Step 2. O(log n)查询
    cin >> m;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; ++i) nums[i] = nums[i - 1] + n - i + 1;
    while (m--) {
        int l, r;
        cin >> l >> r;
        int lf = lower_bound(nums.begin(), nums.end(), l) - nums.begin();
        int rf = lower_bound(nums.begin(), nums.end(), r) - nums.begin();
        int nl = l - nums[lf - 1] - 1;
        int nr = r - nums[rf - 1] - 1;
        if (lf == rf) {  // 在同一段直接求和
            cout << t(lf, lf + nr) - t(lf, lf + nl - 1) << ln;
        } else {
            int ans = 0;
            ans += t(lf, n) - t(lf, lf + nl - 1);  // l到l右端点和
            ans += tsum[rf - 1] - tsum[lf];        // 中间段和
            ans += t(rf, rf + nr);                 // r到r左端点和
            cout << ans << ln;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
