// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace NowCode\JML\i.cpp
 * @date      2024/10/16 13:36:16
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
    vector<int> a(n);

    for (auto &x : a) cin >> x;
    int sum = abs(0 - a[0]);
    for (int i = 1; i < n; i++) {
        sum += abs(a[i] - a[i - 1]);
    }
    sum += abs(a[n - 1] - 0);
    int temp = sum;
    for (int i = 0; i < n; i++) {
        sum = temp;
        if (i == 0) {
            sum -= abs(a[0] - 0);
            sum += abs(a[1] - 0);
            sum -= abs(a[0] - a[1]);

        } else if (i == n - 1) {
            sum -= abs(a[n - 1] - a[n - 2]);
            sum -= abs(a[n - 1] - 0);
            sum += abs(a[n - 2] - 0);
        } else {
            sum -= abs(a[i] - a[i - 1]);
            sum -= abs(a[i + 1] - a[i]);
            sum += abs(a[i + 1] - a[i - 1]);
        }
        cout << sum << " ";
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
