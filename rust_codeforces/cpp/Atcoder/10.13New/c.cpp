// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace Atcoder\10.13New\c.cpp
 * @date      2024/10/13 18:32:28
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
    int n;
    cin >> n;
    vector<vector<int>> qwq(3);
    for (int i = 0; i < 2 * n; i++) {
        int x;
        char y;
        cin >> x >> y;
        switch (y) {
        case 'R': qwq[0].emplace_back(x); break;
        case 'G': qwq[1].emplace_back(x); break;
        case 'B': qwq[2].emplace_back(x); break;
        default: break;
        }
    }
    for (auto &x : qwq) sort(x.begin(), x.end());
    int r = qwq[0].size(), g = qwq[1].size(), b = qwq[2].size();
    if (r % 2 == 0 && g % 2 == 0 && b % 2 == 0) {
        cout << 0 << ln;
        return;
    }
    if (r % 2 == 0) {  // 我们只操作 0 1 ，因此移动到 0 1 为奇数即可
        swap(r, b);
        swap(qwq[0], qwq[2]);
    } else if (g % 2 == 0) {
        swap(g, b);
        swap(qwq[1], qwq[2]);
    }
    // lambda 表达式，等效在外面写函数
    auto check = [](vector<int> p, vector<int> q) -> int {
        int point_p = 0, point_q = 0;
        int len_p = p.size(), len_q = q.size();
        int ans = ll_inf;
        while (point_p < len_p && point_q < len_q) {
            ans = min(ans, abs(p[point_p] - q[point_q]));
            if (p[point_p] < q[point_q]) {
                ++point_p;
            } else {
                ++point_q;
            }
        }
        return ans;
    };
    int ans = check(qwq[0], qwq[1]);
    if (b > 2) ans = min(ans, check(qwq[0], qwq[2]) + check(qwq[1], qwq[2]));
    cout << ans << ln;
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
