// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round69\c.cpp
 * @date      2024/11/24 19:22:42
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
    int n, h;
    cin >> n >> h;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        c = h * 2 - c;
        int g = __gcd(__gcd(a, b), c);
        a /= g;
        b /= g;
        c /= g;
        cout << a << " " << b << " " << c << ln;
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
