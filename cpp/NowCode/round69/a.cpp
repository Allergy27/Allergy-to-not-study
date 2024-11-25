// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round69\a.cpp
 * @date      2024/11/24 19:17:25
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
    cout << 2 * max(n, m) - min(n, m) << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
