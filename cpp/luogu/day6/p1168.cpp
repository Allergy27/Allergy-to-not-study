// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\day6\p1168.cpp
 * @date      2024/10/30 21:05:10
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
    priority_queue<int> qwq;
    priority_queue<int, vector<int>, greater<int>> qaq;
    auto put = [&](auto &a, auto &b) {
        b.push(a.top());
        a.pop();
    };
    for (int i = 0; i < n; ++i) {
        cin >> m;
        if (i & 1) {
            qaq.push(m);
        } else {
            qwq.push(m);
        }
        put(qwq, qaq);
        put(qaq, qwq);
        if (!(i & 1)) cout << qwq.top() << ln;
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
