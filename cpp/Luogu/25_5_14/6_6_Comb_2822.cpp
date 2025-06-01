// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\25_5_14\6_6_Comb_2822.cpp
 * @date      2025/05/14 20:03:42
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
    int _ = 1, p;
    std::cin >> _ >> p;

    std::array<std::array<int, 2700>, 2700> comb;
    std::array<std::array<int, 2700>, 2700> pre;

    comb[0][0] = comb[1][1] = 1 % p;
    for (int i = 2; i <= 2000; ++i) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % p;
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            if (!comb[i][j]) ++pre[i][i];
        }
        pre[i][i + 1] = pre[i][i];
    }

    auto solve = [&]() -> void {
        int n, m;
        std::cin >> n >> m;
        if (m > n)
            std::cout << pre[n][n] << ln;
        else
            std::cout << pre[n][m] << ln;
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
