// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1004 div2\b.cpp
 * @date      2025/05/14 12:34:51
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define PII std::pair<int, int>
#define judge(x) std::cout << ((x) ? "Yes\n" : "No\n")

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int _ = 1;
    std::cin >> _;

    auto solve = [&]() -> void {
        int n;
        std::cin >> n;
        std::map<int, int> qwq;  // 统计每个数出现次数
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            ++qwq[x];
        }

        for (auto [x, _] : qwq)  // 每个数大于2就一个放对面一个放这边，然后多余全+1
            if (qwq[x] > 2) qwq[x + 1] += qwq[x] - 2, qwq[x] = 2;

        bool flag = true;
        for (auto [_, y] : qwq)
            if (y % 2 == 1) flag = false;

        judge(flag);
    };
    auto solve1 = [&]() -> void {
        int n;
        std::cin >> n;
        std::vector<int> qwq(n);
        for (auto &x : qwq) std::cin >> x;
        std::sort(qwq.begin(), qwq.end());
    };
    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
