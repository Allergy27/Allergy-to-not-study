// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\xj\c.cpp
 * @date      2024/11/10 17:31:52
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;
int h[100005], b[100005];
void solve() {
    int n, m;
    string s;
    char ch;
    int cnt = 0;
    int mm = 0;
    cin >> n >> m;
    cin >> ch;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == ch) h[++cnt] = i;
    }
    // for (int i = 1; i <= cnt; i++) cout << h[i] << ' ';
    if (cnt == 0) mm = 1;
    h[cnt + 1] = n * 10;
    cnt = 0;
    h[0] = -n * 10;
    for (int i = 0; i < n; i++) {
        if (i >= h[cnt + 1]) cnt++;
        b[i] = min(abs(i - h[cnt] + 1), abs(h[cnt + 1] - i + 1));
    }
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        if (mm == 1)
            cout << -1 << endl;
        else
            cout << b[x - 1] << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0
}
