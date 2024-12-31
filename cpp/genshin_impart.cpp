// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\genshin_impart
 * @date      2024/11/15 17:10:36
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
}
double dp[1 << 20][20];
int n;
double x[1000], y[1000];
float cal_d(int i, int j) {
    double t1 = x[i] - x[j];
    double t2 = y[i] - y[j];

    return sqrt(t1 * t1 + t2 * t2);
}
void dfs(int i, int s, double val) {
    // cout << dp[s][i] << ' ' << val <<' '<<s<< endl;
    if (val < dp[s][i])
        dp[s][i] = val;
    else
        return;
    for (int j = 1; j <= n; j++) {
        if ((s & (1 << (j - 1))) == 0) {
            // cout<<val<<' '<<s<<endl;
            dfs(j, s | 1 << (j - 1), val + cal_d(i, j));
        }
    }
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    // memset(dp, inf, sizeof(dp));
    for (int i = 0; i <= 1 << 16; i++)
        for (int j = 0; j <= 16; j++)
            dp[i][j] = 1e9;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    // cout<<cal_d(1,2);
    dfs(0, 0, 0);
    double ans = 1e10;
    for (int i = 1; i <= n; i++)
        ans = min(dp[(1 << n) - 1][i], ans);
    // cout <<ans;
    printf("%.2f", ans);
    return 0;
}
