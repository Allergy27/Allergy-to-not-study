// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\week\a.cpp
 * @date      2024/11/10 19:01:21
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
    cin >> n;
    vector<char> l;
    vector<char> r;
    vector<char> qwq;
    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        if ('A' <= x && x <= 'Z')
            r.emplace_back(x);
        else if ('a' <= x && x <= 'z')
            l.emplace_back(x);
        else
            qwq.emplace_back(x);
    }
    for (auto x : qwq) cout << x;
    cout << ln;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
