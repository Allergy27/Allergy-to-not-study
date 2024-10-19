// Copyright 2024 Allergy
// email     Allergy527@gmail.com
// workspace Atcoder\10.5\e.cpp
// date      2024/10/05 21:17:07
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

struct qaq {
    int x;  // 提升幅度
    int y;  // 提升花钱
    bool operator<(const qaq &rhs) const {
        if (x == a.x) return y < a.y;
        return x < a.x;
    }
};

void solve() {
    int n, m, a, p, b, q, ans = 0, l = 0, r = 1;
    cin >> n >> m;
    vector<qaq> qwq(n);  // qvq:提升空间
    for (int i = 0; i < n; ++i) {
        cin >> a >> p >> b >> q;
        if (a >= b && p <= q || b >= a && q <= p) {
            ans += min(p, q);
            qwq[i].x = 0;
            qwq[i].y = 0;
        } else {
            ans += min(p, q);
            qwq[i].x = abs(a - b);
            qwq[i].y = abs(p - q);
        }
    }
    if (m - ans <= 0) {
        cout << "0\n";
        return;
    }
    sort(qwq.begin(), qwq.end());

    while(l != r) {

    }
    ans = m - ans;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
