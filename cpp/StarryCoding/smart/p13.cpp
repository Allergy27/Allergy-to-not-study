// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\StarryCoding\smart\p13.cpp
 * @date      2024/12/03 17:39:38
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
    vector<int> qwq(n);
    int tmp = 0;
    for (auto &x : qwq) {
        cin >> x;
        tmp += x;
    }
    int l = 0, r = tmp / m + 1;
    auto check = [&](int cnt) {
        if (cnt * m > tmp) return false;
        int res = 0;
        for (auto x : qwq) res += min(x, cnt);
        return res >= cnt * m;
    };
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid))
            l = mid + 1;
        else
            r = mid;
    }
    cout << l - 1 << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
