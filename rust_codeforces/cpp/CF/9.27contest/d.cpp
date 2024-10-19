// Copyright 2024 Allergy
// email     Allergy527@gmail.com
// workspace CF\9.27contest\d.cpp
// date      2024/09/28 00:03:42
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
// #define int int64_t
#define ed '\n';

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    unordered_map<int, pair<int, int>> qwq;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (qwq.find(x) == qwq.end())
            qwq[x].first = i, qwq[x].second = i;
        else
            qwq[x].second = i;
    }
    int ans = 0, ans_l = -1, ans_r = n + 1, l = n + 1, r = -1;
    for (auto [i, y] : qwq) {
        l = min(y.first, l);
        r = max(y.second, r);
        if (r - l >= i || ans_l > ans_r) {
            ans = 0;
            break;
        }
        ans_l = max(ans_l, r - i + 1);
        ans_r = min(ans_r, l + i - 1);
        ans = ans_r - ans_l + 1;
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
