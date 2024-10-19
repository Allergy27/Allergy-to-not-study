// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace NowCode\JML\B.cpp
 * @date      2024/10/16 14:31:00
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;
int a[1010][1010];
int r[1010][1010];
int c[1010][1010];
void solve() {
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }

    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            if (i == j) {
                r[i][j] = 0;
                c[i][j] = a[i][j];
            } else {
                int ci = j, cj = i;
                int temp = (a[i][j] + a[ci][cj]) / 2;

                if ((a[i][j] + a[ci][cj]) % 2 == 1) {
                    cout << "NO" << ln;
                    return;
                }
                c[i][j] = c[j][i] = temp;
                r[i][j] = a[i][j] - c[i][j];
                r[j][i] = a[j][i] - c[j][i];
            }
        }

    cout << "YES" << ln;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << c[i][j] << " ";
        }
        cout << ln;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << r[i][j] << " ";
        }
        cout << ln;
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
