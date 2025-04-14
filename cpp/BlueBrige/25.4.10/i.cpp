// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\BlueBrige\25.4.10\i.cpp
 * @date      2025/04/10 18:13:06
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
    std::cin >> n >> m;
    std::vector<std::vector<std::vector<int>>> f(n + 1,
                                                 std::vector<std::vector<int>>(m + 1, std::vector<int>(m + 1, -1)));
    auto dfs = [&](auto &&dfs, int vn, int vm, int res) {
        if (res > vm || vn < 0 || vm < 0 || res < 0) return 0LL;
        if (vn == 0 && vm == 1 && res == 1) return 1LL;
        if (f[vn][vm][res] != -1) return f[vn][vm][res];
        return f[vn][vm][res] = (dfs(dfs, vn - 1, vm, res * 2) + dfs(dfs, vn, vm - 1, res - 1)) % 10000007;
    };

    std::cout << dfs(dfs, n, m, 2) << ln;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
