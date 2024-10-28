// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\flashmen\e.cpp
 * @date      2024/10/26 17:31:52
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
    int n, m, res = 0;
    cin >> m >> n;
    res += (n % 2) * 4 + ((n + 1) / 2) * 7;
    if (res > m)
        cout << (n + 1) / 2 << ln;
    else
        cout << (n + 1) / 2 + (m - res + 14) / 15 << ln;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
