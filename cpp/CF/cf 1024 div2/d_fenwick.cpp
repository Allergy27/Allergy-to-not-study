// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1024 div2\d_fenwick.cpp
 * @date      2025/05/13 16:22:32
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
        int n, m;
        std::cin >> n;

        // FenwickTree
        std::vector<int> fen(n + 1);
        auto add = [&](int i, int w) -> void {
            for (int x = i; x <= n; x += lowbit(x)) fen[x] += w;
        };

        auto query = [&](int i) -> int {
            int ans = 0;
            for (int x = i; x; x -= lowbit(x)) ans += fen[x];
            return ans;
        };

        auto qwq_sort = [&](std::vector<int> &qwq) -> void {
            std::fill(fen.begin(), fen.end(), 0);
            int tmp = 0, n = qwq.size();
            for (int i = n - 1; i >= 0; --i) {
                tmp += query(qwq[i]);
                add(qwq[i], 1);
            }

            std::sort(qwq.begin(), qwq.end());
            if ((tmp % 2) && n >= 2) std::swap(qwq[n - 1], qwq[n - 2]);
        };

        std::vector<int> qwq;
        std::array<std::vector<int>, 2> tmp;
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            tmp[i & 1].emplace_back(x);
        }

        qwq_sort(tmp[0]), qwq_sort(tmp[1]);

        std::array<int, 2> cnt = {0, 0};
        for (int i = 0; i < n; ++i) qwq.emplace_back(tmp[i & 1][cnt[i & 1]++]);
        if (qwq[n - 4] > qwq[n - 2]) {
            std::swap(qwq[n - 4], qwq[n - 2]);
            std::swap(qwq[n - 3], qwq[n - 1]);
        }
        for (auto x : qwq) std::cout << x << ' ';
        std::cout << ln;
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
