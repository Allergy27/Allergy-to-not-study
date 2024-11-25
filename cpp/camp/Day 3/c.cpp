// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\camp\Day 3\c.cpp
 * @date      2024/11/23 12:18:34
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int INF = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

const int mod = 1e9 + 7;
const int maxm = 2e6 + 5;

double cal(int j, int k, const vector<int> &dp, const vector<int> &b) {
    return (dp[j] - dp[k]) * 1.0 / (b[j] - b[k]);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), dp(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    deque<int> dq;
    dq.push_back(0);
    for (int i = 1; i < n; ++i) {
        // 队头去掉劣解
        while (dq.size() > 1 && cal(dq[0], dq[1], dp, b) > -a[i]) dq.pop_front();
        dp[i] = dp[dq.front()] + b[dq.front()] * a[i];
        // 队尾插入i
        while (dq.size() > 1 && cal(i, dq[dq.size() - 2], dp, b) < cal(i, dq.back(), dp, b)) dq.pop_back();
        dq.push_back(i);
    }
    cout << dp[n - 1] << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
