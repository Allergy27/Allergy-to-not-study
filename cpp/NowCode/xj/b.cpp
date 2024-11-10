// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\xj\b.cpp
 * @date      2024/11/10 18:29:05
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;
int vis[100005], h[100005], ans = 0;
vector<int> e[100005], g;
void dfs(int u, int fa) {
    if (vis[u]) return;
    g.push_back(u);
    vis[u] = 1;
    for (int v : e[u]) {
        if (v == fa) continue;
        if (vis[v]) {
            for (int i = g.size() - 1; i >= 0; i--) {
                // cout<<"g[i]:"<<v<<endl;
                if (g[i] == v) {
                    ans += g.size() - i;
                    break;
                }
            }
        }
        dfs(v, u);
    }
    g.pop_back();
}
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        e[i].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        dfs(i, 0);
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
