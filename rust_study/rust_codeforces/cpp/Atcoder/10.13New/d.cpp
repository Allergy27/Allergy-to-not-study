// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace Atcoder\10.13New\d.cpp
 * @date      2024/10/13 19:09:24
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
// #define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m, ans = 0;
    cin >> n >> m;
    map<int, vector<int>> qwq;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        qwq[x].emplace_back(y);
    }
    priority_queue<int> que;
    for (int i = 0; i <= m; ++i) {
        if (qwq.count(i))
            for (auto x : qwq[i]) que.push(x);
        if (!que.empty()) {
            int t = que.top();
            que.pop();
            ans += t;
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
