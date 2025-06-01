// Copyright 2024 Allergy
// email     Allergy527@gmail.com
// workspace CF\9.29contest\a.cpp
// date      2024/09/29 23:26:39
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m, ans = 0, k = 0;
    cin >> n >> m;
    if (n == 0) return;
    if (m == 1) {
        cout << n << '\n';
        return;
    }
    while (n > 0) {
        int tmp = n % m;
        ans += tmp;
        n /= m;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
