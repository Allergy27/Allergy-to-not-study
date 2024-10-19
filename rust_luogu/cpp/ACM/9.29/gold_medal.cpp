// Copyright 2024 Allergy
// email     Allergy527@gmail.com
// workspace ACM\9.29\gold_medal.cpp
// date      2024/09/29 18:31:06
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
// #define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, k, ans = 0, get;
    cin >> n >> k;
    vector<int> qwq(n);
    vector<int> res(n);
    vector<int> pre_res(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> qwq[i];
        ans += qwq[i] / k;
        res[i] = k - qwq[i] % k;
    }
    cin >> get;
    sort(res.begin(), res.end());
    for (int i = 1; i <= n; ++i) {
        pre_res[i] = pre_res[i - 1] + res[i - 1];
    }
    int qvq = upper_bound(pre_res.begin(), pre_res.end(), get) - pre_res.begin();
    if (qvq == n + 1) qvq += (get - pre_res[n]) / k;
    cout << ans + qvq - 1 << "\n";
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
