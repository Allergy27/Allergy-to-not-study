// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\c.cpp
 * @date      2025/01/20 22:41:19
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

int dp[200001][2];
static const int MOD = 998244353;
void solve() {
    int n;
    cin >> n;
    vector<int> qwq(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> qwq[i];
    }
    static int pre[200002][2], cur[200002][2];
    for (int k = 0; k <= n; k++) {
        pre[k][0] = 0;
        pre[k][1] = 0;
    }
    pre[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int k = 0; k <= i; k++) {
            cur[k][0] = 0;
            cur[k][1] = 0;
        }
        for (int k = 0; k <= i; k++) {
            // 诚实
            if (qwq[i] == k) {
                (cur[k][0] += (pre[k][0] + pre[k][1]) % MOD) %= MOD;
            }
            // 说谎
            if (k > 0) {
                (cur[k][1] += pre[k - 1][0]) %= MOD;
            }
        }
        for (int k = 0; k <= i; k++) {
            pre[k][0] = cur[k][0];
            pre[k][1] = cur[k][1];
        }
    }
    int ans = 0;
    for (int k = 0; k <= n; k++) {
        ans = (ans + pre[k][0] + pre[k][1]) % MOD;
    }
    cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
