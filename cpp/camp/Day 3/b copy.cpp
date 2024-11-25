// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\camp\Day 3\b.cpp
 * @date      2024/11/23 12:37:33
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int INF = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

double cal(int j, int k, const vector<int> &dp, const vector<int> &b) {
    return (dp[j] - dp[k]) * 1.0 / (b[j] - b[k]);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n + 1);
    int maxn = 0;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -INF));
    queue<int> q;

    for (int i = 1; i <= n; i++)
        cin >> p[i];
    sort(p.begin() + 1, p.end());
    maxn = p[n];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            for (int u = 1; u <= i; u++) {
                dp[i][j] = max(dp[i][j], dp[u - 1][j - 1] + (i - u + 1) * p[u]);
            }
    cout << dp[n][k] << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
