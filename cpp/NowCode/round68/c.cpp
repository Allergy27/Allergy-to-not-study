// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round68\c.cpp
 * @date      2024/11/17 19:38:13
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
    int n;
    cin >> n;
    unordered_map<int, int> cA, cB;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cA[x]++;
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cB[x]++;
    }

    int delA = 0, delB = 0;
    for (auto& p : cA) {
        int x = p.first;
        if (cB.count(x)) {
            delA += cA[x];
            delB += cB[x];
        }
    }
    int ans = max(delA, delB);
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
