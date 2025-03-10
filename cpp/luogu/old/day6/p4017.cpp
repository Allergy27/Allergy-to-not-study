// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\day6\p4017.cpp
 * @date      2024/10/30 16:52:24
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;
const int MOD = 80112002;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> qwq(n + 1);
    vector<int> assume(n + 1);
    vector<int> eaten(n + 1);
    vector<int> ans(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        qwq[x].emplace_back(y);
        assume[y]++, eaten[x]++;  // y吃x
    }
    auto topsort = [&]() {
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (assume[i]) continue;
            q.push(i);  // 生产者
            ans[i] = 1;
        }
        while (!q.empty()) {  // 还有生产者
            int u = q.front();
            q.pop();
            for (auto v : qwq[u]) {  // 直接消费者
                ans[v] = (ans[u] + ans[v]) % MOD;
                if (!(--assume[v])) q.push(v);
            }
        }
    };
    topsort();
    int res = 0;
    for (int i = 1; i <= n; ++i)  // 所有终极消费者
        if (!eaten[i]) res = (res + ans[i]) % MOD;
    cout << res << ln;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
