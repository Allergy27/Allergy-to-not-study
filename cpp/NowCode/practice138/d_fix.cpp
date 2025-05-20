// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\practice138\d_fix.cpp
 * @date      2025/05/10 14:11:02
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
        int end = 720720;  // LCM of 1-16 : 16 * 9 * 5 * 7 * 11 * 13
        int n, m;
        std::cin >> n;
        std::vector<int> find(16);
        for (int i = 0; i < 16; ++i) find[i] = (1 << (i + 1)) - 1;

        for (int i = 0; i < n; ++i) {
            std::string s;
            std::cin >> s;
            int sz = s.size(), tmp = 0;
            for (int x = 0; x < sz; ++x) tmp |= (s[x] - '0') << x;
            find[sz - 1] &= tmp;
        }
        for (int i = 0; i < end; ++i) {
            bool flag = true;
            for (int x = 0; x < 16; ++x) {
                int tmp = i % (x + 1);
                if (!(find[x] & (1 << tmp))) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                std::cout << i + 1 << ln;
                return;
            }
        }
        std::cout << -1 << ln;
    };

    while (_--) solve();
    std::cin >> _;
    return 0;
}
