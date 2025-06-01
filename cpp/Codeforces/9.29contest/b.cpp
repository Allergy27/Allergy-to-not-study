// Copyright 2024 Allergy
// email     Allergy527@gmail.com
// workspace CF\9.29contest\b.cpp
// date      2024/09/30 00:10:08
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    int q = n + floor(sqrt(n + floor(sqrt(n))));
    cout << q << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
