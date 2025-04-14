// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\new_day1\P2678.cpp
 * @date      2025/04/02 15:39:02
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int end, n, m;
    std::cin >> end >> n >> m;
    std::vector<int> qwq(n);
    for (auto &x : qwq) std::cin >> x;
    qwq.emplace_back(end);

    auto check = [&](int x) {
        int pre_pos = 0, ans = 0;
        for (int i = 0; i <= n; ++i) {
            if (qwq[i] - pre_pos < x)  // 小于预定大小
                ++ans;
            else
                pre_pos = qwq[i];
        }
        return ans <= m;
    };

    int l = 0, r = end, ans = 0;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
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
