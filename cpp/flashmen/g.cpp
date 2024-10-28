// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\flashmen\g.cpp
 * @date      2024/10/26 18:07:10
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
    int a = 0, b, c, d, bit = 1, f = 1;
    cin >> b >> c >> d;
    for (int i = 0; i < 62; ++i) {
        int bit_b = (b & bit) ? 1 : 0;
        int bit_c = (c & bit) ? 1 : 0;
        int bit_d = (d & bit) ? 1 : 0;
        if (bit_b && (!bit_c) && (!bit_d) || (!bit_b) && bit_c && bit_d) {
            f = 0;
            break;
        }
        a |= (bit_b && bit_c) ? bit * (1ll - bit_d) : bit * bit_d;
        bit <<= 1;
    }
    cout << (f ? a : -1) << ln;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
