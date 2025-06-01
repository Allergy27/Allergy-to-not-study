/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace CF\9.21contest\c.cpp
 *@date      2024/09/21 23:38:16
 */
#include <bits/stdc++.h>
#define int __int64

using namespace std;  // NOLINT
using ll = __int64;
int inf = 0x3f3f3f3f;

void solve() {
    int n, m, sum_all = 0;
    cin >> n;
    vector<int> qwq(n);
    for (auto &x : qwq) {
        cin >> x;
        sum_all += x;
    }
    if (n == 1 || n == 2)
        cout << "-1\n";
    else {  // NOLINT
        sort(qwq.begin(), qwq.end());
        int l = 0;
        int r = sum_all * n;
        while (l < r) {  // 平均数为多少超越一半
            int mid = (l + r) >> 1;
            int ans = (sum_all + mid + n - 1) / n;
            if (ans > 2 * qwq[n / 2]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << l << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
