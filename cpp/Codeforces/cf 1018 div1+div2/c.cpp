// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1018 div1+div2\c.cpp
 * @date      2025/04/20 13:09:17
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t
#define PII std::pair<int, int>

using ll = int64_t;
int _inf = 0x3f3f3f3f;
int inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    std::cin >> n;
    std::vector qwq(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) std::cin >> qwq[i][j];
    }
    std::vector<int> a(n);
    for (auto &x : a) std::cin >> x;
    std::vector<int> b(n);
    for (auto &x : b) std::cin >> x;
    int ans = 0;
    for (int tmp = 0; tmp < 2; tmp++) {  // 处理行列
        std::vector<int> dp = {0, a[0]};

        for (int i = 1; i < n; i++) {
            std::vector<int> new_dp = {inf, inf};

            for (int x = 0; x < 2; x++) {
                for (int y = 0; y < 2; y++) {
                    bool flag = true;
                    // 有某一列操作完相邻就不能操作
                    for (int j = 0; j < n; j++) {
                        if (qwq[i][j] + x == qwq[i - 1][j] + y) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) new_dp[x] = std::min(new_dp[x], dp[y] + x * a[i]);
                }
            }

            std::swap(dp, new_dp);
        }

        ans += std::min(dp[0], dp[1]);
        // 转置,处理列
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) std::swap(qwq[i][j], qwq[j][i]);
        }
        std::swap(a, b);
    }
    std::cout << (ans >= inf ? -1 : ans) << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
