// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\April_fool\h.cpp
 * @date      2025/04/03 18:55:49
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::string> ans = {"mgkd",      "jtxu",
                                    "rnb abj",   "ttdu bmk xkjy dddd\nttdu bmk xkjy dddd\nttdu bmk xkjy dddd ",
                                    "lkye iite", "ewgi nnhy"};
    std::cout << ans[n - 1] << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
