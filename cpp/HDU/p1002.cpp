// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\HDU\p1002.cpp
 * @date      2024/10/28 12:32:07
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
    for (int i = 1; i <= n; ++i) {
        string a, b;
        cin >> a >> b;
        cout << "Case " << i << ":\n"
             << a << " + " << b << " = ";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        // char ac[1005] = {0}, bc[1005] = {0};
        int len = max(a.size(), b.size());
        vector<int> qwq(len + 1);
        int tmp = 0;
        for (int j = 0; j < len; ++j) {
            int sum = 0;
            if (j < a.size()) sum += a[j] - '0';
            if (j < b.size()) sum += b[j] - '0';
            sum += tmp;
            tmp = sum / 10;
            qwq[j] = sum % 10;
        }
        if (tmp) qwq[len] = 1;
        for (int j = len - 1 + tmp; j >= 0; --j) cout << qwq[j];
        cout << ln << ln;
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
