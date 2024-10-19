// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace Hello_world.cpp
 * @date      2024/10/12 10:40:35
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;
// int cc[10][1 << 15];
// int dp[11][10000][101];
// struct node {
//     int staute, len, n;
// };
int a[10000000];
int d[5010][100000];
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            cnt++;
            continue;
        }
        int x = 0;
        if (a[i] > 0)
            x += a[i];
        else
            x = cnt - a[i];
        for (int j = 1; j <= cnt; j++) {
            d[j][]
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
