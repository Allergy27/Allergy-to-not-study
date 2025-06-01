// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace CF\10.14contest\a.cpp
 * @date      2024/10/14 22:25:17
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
    string s, t;
    cin >> s;
    cin >> t;
    int n = s.size(), m = t.size();
    int k = min(n, m);
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        if (s[i] == t[i])
            ++ans;
        else
            break;
    }
    if (ans <= 1) {
        cout << n + m << ln;
        return;
    }
    cout << n + m - ans + 1 << ln;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
