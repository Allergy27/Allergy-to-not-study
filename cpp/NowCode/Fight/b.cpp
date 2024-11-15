// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\Fight\b.cpp
 * @date      2024/11/15 19:42:03
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> qwq(n);
    int max_len = 0;
    for (int i = 0; i < n; ++i) {
        cin >> qwq[i];
        int len = 0, num = qwq[i];
        while (num > 0) {
            num /= k;
            len++;
        }
        max_len = max(max_len, len);
    }

    vector<vector<int>> count(max_len, vector<int>(k, 0));
    for (int num : qwq) {
        for (int pos = 0; num > 0; pos++) {
            count[pos][num % k]++;
            num /= k;
        }
    }

    int ans = 0, power = 1;
    for (int pos = 0; pos < max_len; ++pos) {
        int temp = 0;
        for (int i = 0; i < k; ++i) {
            for (int j = i; j < k; ++j) {
                int tmp = (i + j) % k;
                int x = count[pos][i] * count[pos][j];
                if (i == j) {
                    temp += x * tmp;
                } else {
                    temp += x * tmp * 2;
                }
            }
        }
        ans += (temp / 2) * power;
        power *= k;
    }
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
