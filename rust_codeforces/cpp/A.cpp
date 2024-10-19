// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace A.cpp
 * @date      2024/10/09 18:43:05
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
// #define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;
int solve_bad(int A, int B) {
    int i, same = 0, C, intersection, j;
    int score[4] = {1, 2, 4};
    for (i = 0; i < 4; i++) {
        if (A == score[i]) {
            same = same + 1;
        }
        if (B == score[i]) {
            same = same + 1;
        }
    }

    if (A == B) {
        return A;
    } else {
        if (same == 2) {
            return A + B;
        } else if (same == 1) {
            intersection = abs(A - B);
            for (j = 0; j < 4; j++) {
                if (score[j] == intersection) {
                    if (A > B) {
                        return A;
                    } else {
                        return B;
                    }
                }
            }
            return 7;
        } else {
            return 7;
        }
    }
}
int solve_right(int a, int b) {
    return a | b;
}

void solve() {
    for (int i = 0; i <= 7; ++i)
        for (int j = 0; j <= 7; ++j)
            if (solve_bad(i, j) != solve_right(i, j))
                if (i != 0 && j != 0)
                    cout << i << " " << j << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
