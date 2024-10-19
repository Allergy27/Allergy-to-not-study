// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace Atcoder\10.13New\e.cpp
 * @date      2024/10/13 19:37:39
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;

void solve() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector<vector<int>> qwq(n + 1);
    vector<int> dis(n + 1, ll_inf), num(n + 1);  // bfs距离,方案数
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        qwq[x].emplace_back(y);
        qwq[y].emplace_back(x);
    }
    queue<int> que;
    que.push(1);
    dis[1] = 0;
    num[1] = 1;
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        for (auto x : qwq[t]) {
            if (dis[x] > dis[t] + 1) {
                dis[x] = dis[t] + 1;
                num[x] = num[t];
                que.push(x);
            } else if (dis[x] == dis[t] + 1) {
                num[x] = (num[x] + num[t]) % mod;
            }
        }
    }
    cout << num[n] << ln;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
