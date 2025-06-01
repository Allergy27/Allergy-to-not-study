// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace CF\10.14contest\d.cpp
 * @date      2024/10/14 22:25:35
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
// #define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));
    vector<int> qwq(n);
    vector<int> qvq;
    for (auto &x : qwq) cin >> x;

    for (int i = 0; i < n; ++i) {
        if (qwq[i] == 0) {
            qvq.emplace_back(i);
        }
    }
    qvq.emplace_back(n);
    dp[0][0] = 0;

    // Process each interval
    for (int k = 0; k <= m; k++) {
        // Collect the checks in this interval
        vector<int> interval_checks;
        int start = qvq[k] + 1;
        int end = qvq[k + 1];
        for (int pos = start; pos < end; pos++) {
            if (qwq[pos] != 0) {
                interval_checks.push_back(qwq[pos]);
            }
        }

        // Initialize c directly
        vector<int> c(m + 1, 0);
        for (int ri : interval_checks) {
            if (ri < 0) {
                int x = -ri;
                // For s >= x, c[s] += 1
                if (x <= m) {
                    for (int s_new = x; s_new <= m; s_new++) {
                        c[s_new] += 1;
                    }
                }
            } else if (ri > 0) {
                int x = ri;
                int s_r = min(m, k - x);
                // For s <= s_r, c[s] += 1
                if (s_r >= 0) {
                    for (int s_new = 0; s_new <= s_r; s_new++) {
                        c[s_new] += 1;
                    }
                }
            }
        }

        if (k == m) continue;  // No further allocation needed if at the end

        // Update dp[k+1][s_new]
        for (int s = 0; s <= k; s++) {
            if (dp[k][s] == -1) continue;
            int i = k - s;

            // Option 1: Allocate to Strength
            int s_new = s + 1;
            if (s_new <= m) {
                dp[k + 1][s_new] = max(dp[k + 1][s_new], dp[k][s] + c[s_new]);
            }

            // Option 2: Allocate to Intelligence
            s_new = s;
            dp[k + 1][s_new] = max(dp[k + 1][s_new], dp[k][s] + c[s_new]);
        }
    }

    // Find the maximum answer in the last row of dp
    int ans = *max_element(dp[m].begin(), dp[m].end());
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
