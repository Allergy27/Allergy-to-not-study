// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round68\d.cpp
 * @date      2024/11/17 20:01:23
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
    vector<int> qwq(n);
    vector<int> count(12, 0);
    for (int i = 0; i < n; ++i) {
        cin >> qwq[i];
        int cnt3 = 0, cnt5 = 0, cnt11 = 0;
        int temp = qwq[i];
        while (temp % 3 == 0) {
            temp /= 3;
            cnt3++;
        }
        cnt3 = min(cnt3, static_cast<int>(2));
        cnt5 = (temp % 5 == 0) ? 1 : 0;

        cnt11 = (temp % 11 == 0) ? 1 : 0;

        int idx = cnt3 * 4 + cnt5 * 2 + cnt11;
        count[idx]++;
    }

    vector<vector<bool>> check(12, vector<bool>(12, false));
    for (int i = 0; i < 12; ++i) {
        int c3_i = i / 4;
        int c5_i = (i % 4) / 2;
        int c11_i = i % 2;
        for (int j = i; j < 12; ++j) {
            int c3_j = j / 4;
            int c5_j = (j % 4) / 2;
            int c11_j = j % 2;

            if (c3_i + c3_j >= 2 && c5_i + c5_j >= 1 && c11_i + c11_j >= 1) {
                check[i][j] = true;
            }
        }
    }

    int pr = 0;
    for (int i = 0; i < 12; ++i) {
        for (int j = i; j < 12; ++j) {
            if (check[i][j]) {
                if (i == j) {
                    pr += count[i] * (count[i] - 1) / 2;
                } else {
                    pr += count[i] * count[j];
                }
            }
        }
    }

    int ans = pr;

    for (int i = 0; i < n; ++i) {
        int cnt3 = 0, cnt5 = 0, cnt11 = 0;
        int temp = qwq[i];
        while (temp % 3 == 0) {
            temp /= 3;
            cnt3++;
        }
        cnt3 = min(cnt3, static_cast<int>(2));
        cnt5 = (temp % 5 == 0) ? 1 : 0;
        cnt11 = (temp % 11 == 0) ? 1 : 0;
        int from = cnt3 * 4 + cnt5 * 2 + cnt11;
        temp = qwq[i] + 1;
        cnt3 = 0;
        while (temp % 3 == 0) {
            temp /= 3;
            cnt3++;
        }
        cnt3 = min(cnt3, static_cast<int>(2));
        cnt5 = (temp % 5 == 0) ? 1 : 0;
        cnt11 = (temp % 11 == 0) ? 1 : 0;
        int to = cnt3 * 4 + cnt5 * 2 + cnt11;

        if (from == to) continue;  // 类别未变化
        count[from]--;
        count[to]++;
        int res = 0;
        for (int i = 0; i < 12; ++i) {
            for (int j = i; j < 12; ++j) {
                if (check[i][j]) {
                    if (i == j) {
                        res += count[i] * (count[i] - 1) / 2;
                    } else {
                        res += count[i] * count[j];
                    }
                }
            }
        }
        count[from]++;
        count[to]--;

        ans = max(ans, res);
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
