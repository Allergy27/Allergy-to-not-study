// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\camp\Day 1. Number Theory\b.cpp
 * @date      2024/11/19 20:57:05
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

void solve() {
    int n, m = -ll_inf;
    cin >> n;
    vector<int> qwq(n);
    for (auto &x : qwq) {
        cin >> x;
        m = max(m, x);
    }
    // 预处理出cnt
    vector<int> cnt(m + 1);
    for (auto x : qwq) cnt[x] += 1;
    for (int x = 1; x <= m; ++x)
        for (int y = 2 * x; y <= m; y += x) {
            cnt[x] += cnt[y];
        }
    // 预处理出 f = 2^cnt[x] - 1
    int flim = *max_element(cnt.begin(), cnt.end());
    vector<int> pow2(flim + 1, 1);
    for (int i = 1; i <= flim; ++i)
        pow2[i] = (pow2[i - 1] << 1) % MOD;

    vector<int> g(m + 1);
    for (int x = m; x > 0; --x) {
        g[x] = (cnt[x] * pow2[cnt[x] - 1]) % MOD;
        for (int y = 2 * x; y <= m; y += x)
            g[x] = (g[x] - g[y] + MOD) % MOD;
    }

    int ans = 0;
    for (int x = 2; x <= m; ++x)
        ans = (ans + (g[x] * x) % MOD) % MOD;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
