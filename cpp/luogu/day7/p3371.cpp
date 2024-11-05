// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\day7\p3371.cpp
 * @date      2024/11/04 11:52:48
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

int head[100000], cnt;
int ans[1000000];
bool vis[1000000];
int m, n, s;
struct edge {
    int to;
    int nextt;
    int wei;
} edge[1000000];
void addedge(int x, int y, int z) {
    edge[++cnt].to = y;
    edge[cnt].wei = z;
    edge[cnt].nextt = head[x];
    head[x] = cnt;
}
void solve() {
    cin >> m >> n >> s;
    for (int i = 1; i <= n; i++) {
        ans[i] = 2147483647;
    }
    ans[s] = 0;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        addedge(a, b, c);
    }
    int pos = s;
    while (vis[pos] == 0) {
        int minn = 2147483647;
        vis[pos] = 1;
        for (int i = head[pos]; i != 0; i = edge[i].nextt) {
            if (!vis[edge[i].to] && ans[edge[i].to] > ans[pos] + edge[i].wei) {
                ans[edge[i].to] = ans[pos] + edge[i].wei;
            }
        }
        for (int i = 1; i <= m; i++) {
            if (ans[i] < minn && vis[i] == 0) {
                minn = ans[i];
                pos = i;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << ' ';
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
