/* Copyright 2025 Allergy
 * @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\25_5_15\4_1_DP_2501.cpp
 * @date      2025/05/15 18:28:53
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define judge(x) std::cout << ((x) ? "Yes\n" : "No\n")

using ll = int64_t;
using PII = std::pair<int, int>;
using PDD = std::pair<double, double>;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int _ = 1;
    // std::cin >> _;

    auto solve = [&]() -> void {
        int n;
        std::cin >> n;
        std::vector<ll> qwq(n + 1);
        for (int i = 1; i <= n; ++i) std::cin >> qwq[i];

        // Problem 1: 最长不降子序列
        std::vector<ll> cnt(n + 2);
        for (int i = 1; i <= n; ++i) cnt[i] = qwq[i] - i;

        std::vector<ll> stk;
        std::vector<int> le(n + 2);                // 记录每个i的最长子序列长度
        std::vector<std::vector<int>> cur(n + 2);  // cur[len]保存该长度的i的索引

        for (int i = 1; i <= n; ++i) {
            if (stk.empty() || stk.back() <= cnt[i]) {
                stk.push_back(cnt[i]);
                le[i] = stk.size();
                cur[le[i]].push_back(i);
            } else {
                auto p = std::upper_bound(stk.begin(), stk.end(), cnt[i]) - stk.begin();
                stk[p] = cnt[i];
                le[i] = p + 1;
                cur[le[i]].push_back(i);
            }
        }
        std::cout << n - stk.size() << ln;

        // Problem 2: 动态规划计算最小代价
        // 添加虚拟节点0和n+1
        cnt[0] = -ll_inf;
        le[0] = 0;
        cur[0].push_back(0);

        cnt[n + 1] = ll_inf;
        le[n + 1] = stk.size() + 1;
        cur[le[n + 1]].push_back(n + 1);

        std::vector<ll> f(n + 2, ll_inf);
        f[0] = 0;
        std::vector<ll> qaq1(n + 2), qaq2(n + 2);
        for (int j = 1; j <= n + 1; ++j) {
            int len_j = le[j];
            if (len_j == 0) continue;  // 不可能，因为j>=1
            for (int i : cur[len_j - 1]) {
                if (i >= j || cnt[i] > cnt[j]) continue;
                qaq1[i] = qaq2[j] = 0;
                for (int q = i + 1; q < j; ++q) qaq1[q] = qaq1[q - 1] + std::abs(cnt[q] - cnt[i]);
                for (int q = j - 1; q > i; --q) qaq2[q] = qaq2[q + 1] + std::abs(cnt[q] - cnt[j]);
                // 两个前缀和

                ll ans = ll_inf;
                for (int k = i; k < j; ++k) ans = std::min(ans, qaq1[k] + qaq2[k + 1]);
                f[j] = std::min(f[j], f[i] + ans);
            }
        }
        std::cout << f[n + 1] << ln;
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
