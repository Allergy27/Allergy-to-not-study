// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\b.cpp
 * @date      2025/01/21 00:02:14
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    std::cin >> n;
    std::map<int, int> count;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        count[x]++;
    }
    std::vector<int> pairs;
    std::vector<int> singles;
    for (auto [x, y] : count) {
        if (y > 3) {
            std::cout << x << ' ' << x << ' ' << x << ' ' << x << ln;
            return;
        } else if (y == 3) {
            singles.push_back(x);
            pairs.push_back(x);
        } else if (y > 1) {
            pairs.push_back(x);
        } else {
            singles.push_back(x);
        }
    }
    if (pairs.size() == 0) {
        std::cout << -1 << ln;
        return;
    } else if (pairs.size() > 1) {
        std::cout << pairs[0] << ' ' << pairs[0] << ' ' << pairs[1] << ' ' << pairs[1] << ln;
        return;
    }
    m = singles.size();
    int tmp = pairs[0] * 2;
    for (int i = 1; i < m; i++) {
        if (singles[i] - singles[i - 1] < tmp) {
            std::cout << singles[i] << ' ' << singles[i - 1] << ' ' << pairs[0] << ' ' << pairs[0] << ln;
            return;
        }
    }
    std::cout << -1 << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
