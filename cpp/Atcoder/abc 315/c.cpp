// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\Atcoder\abc 315\c.cpp
 * @date      2024/11/20 20:23:54
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
    vector<priority_queue<int>> flavor(n + 1);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        flavor[x].push(y);
    }
    priority_queue<int> res;
    int ans_tmp = 0;
    for (auto x : flavor) {
        if (x.empty()) continue;
        int tmp = 0;
        res.push(x.top());
        tmp += x.top();
        x.pop();
        if (!x.empty()) {
            tmp += x.top() / 2;
            ans_tmp = max(ans_tmp, tmp);
        }
    }
    int ans = res.top();
    res.pop();
    if (!res.empty()) {
        ans += res.top();
    } else {
        ans = 0;
    }
    cout << max(ans, ans_tmp) << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
