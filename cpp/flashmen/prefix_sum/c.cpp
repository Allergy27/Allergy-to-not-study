// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\flashmen\prefix_sum\c.cpp
 * @date      2024/11/02 20:18:51
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
    string s;
    cin >> s;
    vector<int> qaq(n);  // 前缀和数组
    int idx = 1;
    while (idx < n) {
        qaq[idx] = qaq[idx - 1];
        // 遇到AC就往后跳两步
        if (s[idx - 1] == 'A' && s[idx] == 'C') ++qaq[idx];
        idx++;
    }
    // 前缀和处理查询
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << qaq[r - 1] - qaq[l - 1] << ln;
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
