// Copyright 2024 Allergy
// email     Allergy527@gmail.com
// workspace CF\9.27contest\d.cpp
// date      2024/09/28 00:03:42
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
// #define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

struct node {
    int l, r;
};

void solve() {
    int n;
    cin >> n;
    map<int, node> qwq;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (qwq.find(x) == qwq.end()) {
            qwq[x] = {i, i};
        } else {
            qwq[x].r = i;
        }
    }
    node ans = {-1, n + 1}, tmp = {n + 1, -1};
    for (auto [x, y] : qwq) {
        tmp.l = min(tmp.l, y.l);
        tmp.r = max(tmp.r, y.r);
        if (tmp.r - tmp.l >= x || ans.l > ans.r) {
            ans.r = 0, ans.l = 1;
            break;
        }
        ans.l = max(ans.l, tmp.r - x + 1);
        ans.r = min(ans.r, tmp.l + x - 1);
    }
    cout << ans.r - ans.l + 1 << '\n';
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
