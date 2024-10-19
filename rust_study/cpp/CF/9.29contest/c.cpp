// Copyright 2024 Allergy
// email     Allergy527@gmail.com
// workspace CF\9.29contest\c.cpp
// date      2024/09/30 00:48:52
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define int unsigned long long

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int b, c, d;
    cin >> b >> c >> d;
    bitset<64> b_b(b), b_c(c), b_d(d);
    bitset<64> a;
    bool found = true;
    for (int i = 0; i < 64; ++i) {
        tuple<int, int, int> t = {b_b[i], b_c[i], b_d[i]};
        if (false) {
        } else if (t == make_tuple(0, 0, 0)) {
            a[i] = 0;
        } else if (t == make_tuple(0, 0, 1)) {
            a[i] = 1;
        } else if (t == make_tuple(0, 1, 0)) {
            a[i] = 1;
        } else if (t == make_tuple(1, 0, 1)) {
            a[i] = 1;
        } else if (t == make_tuple(1, 1, 0)) {
            a[i] = 1;
        } else if (t == make_tuple(1, 1, 1)) {
            a[i] = 0;
        } else {
            found = false;
            break;
        }
    }
    if (found) {
        int ans = a.to_ullong();
        cout << ans << '\n';
    } else {
        cout << "-1\n";
    }
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
