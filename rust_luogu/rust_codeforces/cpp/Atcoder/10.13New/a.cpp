// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace Atcoder\10.13New\a.cpp
 * @date      2024/10/13 17:21:44
 */
#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
// #define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] >= s[i - 1]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
