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
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    // 排序确保 p[u] 是单调递增的
    sort(p.begin() + 1, p.end());

    // 初始化 dp，注意 dp 的值域设置
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -INF));
    dp[0][0] = 0;

    // 动态规划
    for (int j = 1; j <= k; j++) {
        deque<int> dq;
        for (int i = 1; i <= n; i++) {
            // 队头不符合当前范围时弹出
            while (!dq.empty() && dq.front() < i - (n / k)) dq.pop_front();

            // 更新 dp[i][j]，队头是当前最优的 u
            if (!dq.empty()) {
                int u = dq.front();
                dp[i][j] = dp[u - 1][j - 1] + (i - u + 1) * p[u];
            }

            // 队尾维护单调性，确保斜率递减
            while (!dq.empty() && dp[dq.back() - 1][j - 1] - dq.back() * p[dq.back()] <=
                                      dp[i - 1][j - 1] - i * p[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
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
