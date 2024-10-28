// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 982 div2\a.cpp
 * @date      2024/10/26 22:32:35
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

int lis(const vector<int> &nums) {
    int n = nums.size();

    vector<int> f(n);

    for (int i = 0; i < n; i++) {
        f[i] = 0;
        for (int j = 0; j < i; j++) {
            if (nums[j] <= nums[i]) {
                f[i] = max(f[i], f[j]);
            }
        }
        f[i]++;
    }

    return *max_element(f.begin(), f.end());
}

void solve() {
    int n, m;
    cin >> n;
    vector<int> qwq(n);
    for (auto &x : qwq) cin >> x;
    int ans = n;
    for (int i = 0; i < n; ++i) {
        int tmp = i;
        for (int j = i ; j < n; ++j) {
            cout << qwq[j] << ' ';
            if (qwq[j] > qwq[i]) {
                ++tmp;
            }
        }
        cout << "? " << tmp << ln;

        ans = min(ans, tmp);
    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
