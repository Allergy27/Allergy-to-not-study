// Copyright 2024 Allergy
// email     Allergy527@gmail.com
// workspace CF\9.27contest\b.cpp
// date      2024/09/27 22:13:36
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> qwq(n + 1);
    for (int i = 1; i <= n; i++) cin >> qwq[i];
    vector<int> qaq(n + 1);
    unordered_map<int, int> ans;
    for (int i = 1; i <= n - 1; i++) {
        int j = n - i + 1;
        ans[i * (n - i + 1) - 1]++;
        ans[i * (n - i)] += qwq[i + 1] - qwq[i] - 1;
    }
    ans[n - 1]++;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        cout << ans[a] << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
