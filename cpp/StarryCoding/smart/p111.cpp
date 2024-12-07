// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\StarryCoding\smart\p111.cpp
 * @date      2024/12/03 17:50:33
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
    vector<unordered_set<int>> qaq(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        qaq[i].insert(x);
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        if (qaq[x].size() > qaq[y].size()) swap(qaq[x], qaq[y]);
        for (auto x : qaq[x]) qaq[y].insert(x);
        qaq[x].clear();
        cout << qaq[y].size() << endl;
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
