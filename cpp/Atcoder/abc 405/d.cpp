// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\Atcoder\abc 405\d.cpp
 * @date      2025/05/10 20:20:31
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
        int n, m;
        std::cin >> n >> m;
        std::vector<std::string> ss(n);
        for (int i = 0; i < n; ++i) std::cin >> ss[i];
        std::vector qwq(n + 2, std::vector<char>(m + 2));

        std::queue<PII> que;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (ss[i][j] == 'E') que.push({i + 1, j + 1});
                qwq[i + 1][j + 1] = ss[i][j];
            }
        }

        // BFS
        const int WAY[5] = {-1, 0, 1, 0, -1};
        const char QWQ[4] = {'v', '<', '^', '>'};
        while (!que.empty()) {
            auto [x, y] = que.front();
            que.pop();
            for (int i = 0; i < 4; ++i) {
                int p = x + WAY[i], q = y + WAY[i + 1];
                if (qwq[p][q] == '.') {
                    qwq[p][q] = QWQ[i];
                    que.push({p, q});
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) std::cout << qwq[i][j];
            std::cout << ln;
        }
    };

    while (_--) solve();
    std::cin >> _;
    return 0;
}
