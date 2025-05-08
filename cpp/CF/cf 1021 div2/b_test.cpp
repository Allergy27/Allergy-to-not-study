// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1021 div2\b_test.cpp
 * @date      2025/04/26 17:35:40
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t
#define PII std::pair<int, int>

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    std::vector<int> p = {1, 2, 9, 5, 10, 13};
    auto f = [&](int x, int y) {
        std::set<int> ans;
        for (int i = 0; i <= 20; ++i) {
            int tmp = 0;
            for (int j = 0; j < p.size(); ++j) {
                if (j != x && j != y) tmp += std::abs(i - p[j]);
            }
            ans.insert(tmp);
        }
        return *std::max_element(ans.begin(), ans.end());
    };
    int n = p.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) ans = std::max(ans, f(i, j));
        }
    }
    std::cout << ans << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
