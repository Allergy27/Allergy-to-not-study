// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\flashmen\prefix_sum\a.cpp
 * @date      2024/11/02 18:16:00
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
    for (auto &i : qwq) cin >> i;
    sort(qwq.begin(), qwq.end());                      // 排序O(nlogn)
    for (int i = 1; i < n; i++) qwq[i] += qwq[i - 1];  // 预处理出前缀和
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        // 二分查询O(logn) 共m次 O(mlogn)
        cout << upper_bound(qwq.begin(), qwq.end(), x) - qwq.begin() << ln;
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
