/* Copyright 2025 Allergy
 * @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\5_18_VP\f.cpp
 * @date      2025/05/18 09:53:34
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
    std::cin >> _;

    auto solve = [&]() -> void {
        int n, m;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        std::vector<int> l_cnt(n), r_cnt(n);
        l_cnt[0] = s[0] == '(';
        r_cnt[n - 1] = s[n - 1] == ')';
        for (int i = 1; i < n; ++i) l_cnt[i] = l_cnt[i - 1] + (s[i] == '(');
        for (int i = n - 2; i >= 0; --i) r_cnt[i] = r_cnt[i + 1] + (s[i] == ')');
        int ans = inf;
        for (int i = 0; i < n; ++i)
            if (i > 0 && s[i] == '(' && s[i - 1] == ')') ans = std::min(ans, r_cnt[i] + l_cnt[i - 1]);
        ans = std::min(r_cnt[0], ans);
        ans = std::min(l_cnt[n - 1], ans);
        std::cout << ans << ln;
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
