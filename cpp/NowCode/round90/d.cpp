// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round90\d.cpp
 * @date      2025/04/20 19:48:03
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
    std::vector<std::string> qwq(n);
    // 0 -> 25tot | 1 -> 2tot | 2 -> 5tot
    std::vector cnt(n, std::vector<int>(3));
    for (int i = 0; i < n; ++i) {
        std::cin >> qwq[i];
        int tot25 = 0, tot2 = 0, tot5 = 0;
        for (auto y : qwq[i]) {
            if (y == '2') {
                ++tot2;
            } else if (y == '5') {
                ++tot5;
                tot25 += tot2;
            }
        }
        cnt[i][0] = tot25, cnt[i][1] = tot2, cnt[i][2] = tot5;
    }
    auto check = [&](int target) {
        int max = 0, tmp = 0, tmp2 = 0, time = 0;
        for (int i = 0; i < n; ++i) {
            if (tmp + cnt[i][0] + tmp2 * cnt[i][2] > target) {
                ++time;
                if (time >= m) return false;
                max = std::max(max, tmp);
                tmp = cnt[i][0];
                tmp2 = cnt[i][1];
            } else {
                tmp += cnt[i][0] + tmp2 * cnt[i][2];
                max = std::max(max, tmp);
                tmp2 += cnt[i][1];
            }
        }
        max = std::max(max, tmp);
        return max <= target;
    };
    int l = 0, r = ll_inf, ans = ll_inf;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
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
