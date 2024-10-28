// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\flashmen\c.cpp
 * @date      2024/10/26 16:41:33
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {  // 解题部分
    int n, m, i, f = 0, ans = 0;
    cin >> n >> m;
    vector<char> s(n);
    for (auto &x : s) {
        cin >> x;
        if (x == 'B') ++ans;
    }
    if (ans < m) {
        f += 2;
        for (i = 0; i < n && ans != m; ++i)
            if (s[i] == 'A') ++ans;
    } else if (ans > m) {
        f += 1;
        for (i = 0; i < n && ans != m; ++i)
            if (s[i] == 'B') --ans;
    }
    cout << (f ? "1\n" : "0\n");
    if (f != 0)
        cout << i << ' ' << "AB"[f - 1] << ln;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
