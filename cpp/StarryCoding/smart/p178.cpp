// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\StarryCoding\smart\p178.cpp
 * @date      2024/12/03 18:39:10
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
    int ans = 0;
    for (int i = 1; i <= n / i; ++i)
        for (int j = 1; j <= m / j; ++j)
            if (__gcd(i, j) == 1) ans += min(n / i, m / j) / (i + j);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
