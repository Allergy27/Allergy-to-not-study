// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round92\f.cpp
 * @date      2025/05/11 19:02:18
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define PII std::pair<int, int>

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int _ = 1;
    // std::cin >> _;

    auto solve = [&]() -> void {
        auto xor_sum = [](int n) {
            int res[] = {n, 1, n + 1, 0};
            return res[n % 4];
        };

        int n, m;
        std::cin >> n >> m;
        int total = n + m;
        int pre_sum = xor_sum(total);
        if (pre_sum != 0) {
            std::cout << -1 << ln;
            return;
        }
        // 状压DP
        // dp[i][j] = k 表示选了i个数，异或和为j是否可达
        // n, m <= 500, 异或和最大不会超过2048
        const int MAXN = 502, MAXX = 4096;
        std::vector<std::bitset<MAXX>> dp(n + 2);
        dp[0][0] = 1;
        std::vector pre(n + 2, std::vector<int>(MAXX, -1));
        std::vector from(n + 2, std::vector<int>(MAXX, -1));
        for (int num = 1; num <= total; ++num) {
            for (int cnt = n; cnt >= 0; --cnt) {
                for (int x = 0; x < MAXX; ++x) {
                    if (dp[cnt][x]) {
                        dp[cnt + 1][x ^ num] = 1;
                        if (pre[cnt + 1][x ^ num] == -1) {
                            pre[cnt + 1][x ^ num] = x;
                            from[cnt + 1][x ^ num] = num;
                        }
                    }
                }
            }
        }
        // 找到一组划分
        int target = -1;
        for (int x = 0; x < MAXX; ++x) {
            if (dp[n][x] && dp[m][x]) {
                target = x;
                break;
            }
        }
        if (target == -1) {
            std::cout << -1 << ln;
            return;
        }
        // 可选：输出一组划分
        std::vector<int> part;
        int cnt = n, x = target;
        std::vector<bool> used(total + 1, false);
        while (cnt > 0) {
            int num = from[cnt][x];
            part.emplace_back(num);
            used[num] = true;
            x = pre[cnt][x];
            cnt--;
        }

        std::vector qwq(n, std::vector<int>(m));
        for (int i = 0; i < n; ++i) qwq[i][m - 1] = part[i];

        qwq[n - 1][m - 1] = target;

        part.clear();
        for (int i = 1; i <= total; ++i)
            if (!used[i]) part.emplace_back(i);
        for (int i = 0; i < m - 1; ++i) qwq[n - 1][i] = part[i];
        for (auto x : qwq) {
            for (auto y : x) std::cout << y << ' ';
            std::cout << ln;
        }
    };

    while (_--) solve();
    std::cin >> _;
    return 0;
}
