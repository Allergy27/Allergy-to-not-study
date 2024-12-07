// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round68\d.cpp
 * @date      2024/11/17 20:01:23
 */
#include <bits/stdc++.h>
#define int int64_t
using namespace std;  // NOLINT
const int mod = 495;

void solve() {
    int n, ans;
    cin >> n;
    vector<int> f(527);
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        f[x % mod]++;
    }
    auto check = [&]() {
        int res = 0;
        for (int i = 0; i < mod; i++)
            for (int j = i; j < mod; j++)
                if (i * j % mod == 0) {
                    if (i == j)
                        res += f[i] * (f[i] - 1) / 2;
                    else
                        res += f[i] * f[j];
                }
        return res;
    };
    ans = check();
    for (int i = 0; i < mod; i++) {
        if (!f[i]) continue;
        f[i]--, f[(i + 1) % mod]++;
        ans = max(ans, check());
        f[i]++, f[(i + 1) % mod]--;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
