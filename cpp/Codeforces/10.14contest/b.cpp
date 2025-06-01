// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace CF\10.14contest\b.cpp
 * @date      2024/10/14 22:25:29
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;
int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> qwq(n);
    vector<int> qaq(n);
    for (auto &x : qwq) cin >> x;
    for (auto &x : qaq) cin >> x;
    auto qpow = [&](int a, int b) -> int {
        int ans = 1;
        while (b) {
            if (b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return ans;
    };
    for (int i = 0; i < n; ++i)
        cout << qpow(2, qaq[i]) << ln;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
