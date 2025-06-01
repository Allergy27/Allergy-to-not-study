// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1019 div2\c.cpp
 * @date      2025/04/22 15:53:49
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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> qwq(n);
    for (auto &x : qwq) std::cin >> x;

    std::vector<int> pre(n + 1);
    std::vector<int> suf(n + 1);

    for (int i = 0; i < n; ++i) pre[i + 1] = pre[i] + (qwq[i] <= m ? -1 : 1);
    for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + (qwq[i] <= m ? -1 : 1);

    int flag = 0;

    if (*std::min_element(pre.begin() + 2, pre.end()) < 0) flag = 1;
    if (*std::min_element(suf.begin(), suf.end() - 2) < 0) flag = 1;
    if (std::count(pre.begin() + 1, pre.end(), 0) > 1) flag = 1;
    if (std::count(suf.begin(), suf.end() - 1, 0) > 1) flag = 1;

    int l = 1, r = n - 1;
    while (l < r && pre[l] > 0) ++l;
    while (l < r && suf[r] > 0) --r;
    if (flag == 0) flag = l < r;

    if (flag)
        std::cout << "Yes" << ln;
    else
        std::cout << "No" << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
