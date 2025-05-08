// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 905 div2\g.cpp
 * @date      2025/04/15 09:35:53
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
    std::vector<int> qwq(n - 1), qvq(n);
    for (auto &x : qwq) std::cin >> x;
    for (auto &x : qvq) std::cin >> x;
    std::sort(qwq.begin(), qwq.end());
    std::sort(qvq.begin(), qvq.end());

    int res_max = 0;
    std::vector<int> vail(n, 1);
    int ans = 0, match = 0;
    for (int i = 0; i < n - 1; ++i) {
        while (match < n && qwq[i] >= qvq[match]) ++match;
        if (match == n) {
            ans = n - i - 1;
            break;
        }
        vail[match++] = 0;
    }
    for (int i = 0; i < n; ++i)
        if (vail[i]) res_max = std::max(res_max, qvq[i]);
    int time_plus = std::max(0LL, m - res_max + 1);
    int time_noml = std::max(0LL, m - time_plus);
    std::cout << ans * time_noml + (ans + 1) * time_plus << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
