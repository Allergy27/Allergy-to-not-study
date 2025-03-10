// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\Atcoder\abc 389\c.cpp
 * @date      2025/01/18 20:22:30
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    std::cin >> n;
    std::vector<std::pair<int, int>> qwq;  // 坐标 长度
    int tmp_x = 0, tmp_y = 0;              // 偏移量

    while (n--) {
        int x, y;
        std::cin >> x;

        if (x == 1) {
            std::cin >> y;
            if (!qwq.empty()) {
                auto [p, q] = qwq.back();
                qwq.push_back({p + q, y});
            } else {
                qwq.push_back({0, y});
            }
        }
        if (x == 2) {
            tmp_y += qwq[tmp_x].second;
            tmp_x += 1;
        }
        if (x == 3) {
            std::cin >> y;
            std::cout << qwq[tmp_x + y - 1].first - tmp_y << ln;
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
