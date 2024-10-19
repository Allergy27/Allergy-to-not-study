// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace Atcoder\10.13New\b.cpp
 * @date      2024/10/13 17:26:29
 */
#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int l, r;
    cin >> l >> r;
    for (int w = r - l; w > 0; w--) {
        for (int j = l; j < r - w + 1; ++j) {
            if (__gcd(j, j + w) == 1) {
                cout << w << '\n';
                return;
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
