// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\practice138\a.cpp
 * @date      2025/05/09 19:15:21
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
        std::cin >> n;
        std::vector<char> qwq(n);
        for (auto &x : qwq) std::cin >> x;
        int ans = 0, res = 0;
        for (int i = 0; i < n; ++i) {
            int tmp, _nm;
            char _s;
            std::cin >> tmp >> _s >> _nm;
            if (tmp > res) res = tmp, ans = i;
        }
        std::cout << qwq[ans] << ln;
    };

    while (_--) solve();
    std::cin >> _;
    return 0;
}
