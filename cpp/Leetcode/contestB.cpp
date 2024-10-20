// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\Leetcode\contestB.cpp
 * @date      2024/10/20 11:41:06
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
    string s;
    int m;
    cin >> s >> m;
    int n = s.size();
    int ans = 0;
    for (int l = 0; l < n; ++l) {
        map<char, int> qwq;
        for (int r = l; r < n; ++r) {
            ++qwq[s[r]];
            if (qwq[s[r]] == 2) {
                ans += n - r;
                break;
            }
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
