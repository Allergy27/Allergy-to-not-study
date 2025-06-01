// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\25_5_8\4_11_DP_2602.cpp
 * @date      2025/05/08 15:33:27
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

    std::unordered_map<int, int> mem;
    int tmp = m, len = 1;
    while (tmp > 0) tmp /= 10, ++len;

    std::vector<int> now(len), max(len), p(len);
    max[0] = 1;
    for (int i = 1; i < len; ++i) max[i] = max[i - 1] * 10;

    auto dfs = [&](auto &&dfs, int u, int m, bool is_limit, bool is_zero) -> int {
        if (u == 0) return 0;

        if (!is_limit && !is_zero && mem.contains(u)) return mem[u];

        int cnt = 0;
        int up = is_limit ? p[u] : 9;
        for (int i = 0; i <= up; ++i) {  // 这一位填的数字
            if (is_zero && i == 0)
                cnt += dfs(dfs, u - 1, m, is_limit && i == up, true);
            else if (i == m && is_limit && i == up)  // 前面的位全顶满
                cnt += now[u - 1] + 1 + dfs(dfs, u - 1, m, is_limit && i == up, false);
            else if (i == m)  // 前面的和当前的全顶满
                cnt += max[u - 1] + dfs(dfs, u - 1, m, is_limit && i == up, false);
            else
                cnt += dfs(dfs, u - 1, m, is_limit && i == up, false);
        }
        if ((!is_limit) && (!is_zero)) mem[u] = cnt;
        return cnt;
    };

    auto f = [&](int x, int digit) {
        mem.clear();
        int i = 0;
        while (x) {
            p[++i] = x % 10;
            x /= 10;
            now[i] = now[i - 1] + p[i] * max[i - 1];
        }
        return dfs(dfs, i, digit, true, true);
    };

    for (int i = 0; i < 10; ++i) std::cout << (f(m, i) - f(n - 1, i)) << ' ';
    std::cout << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
