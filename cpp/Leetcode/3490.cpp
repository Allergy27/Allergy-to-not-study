// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\Leetcode\3490.cpp
 * @date      2025/05/08 17:49:09
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t
#define PII std::pair<int, int>

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;
using namespace std;  // NOLINT

class Solution {
 public:
    int beautifulNumbers(int l, int r) {
        unordered_map<int64_t, int> mem;
        vector<int> high;
        auto dfs = [&](this auto &&dfs, int u, int mul, int sum, bool is_limit, bool is_zero) -> int {
            if (u < 0) return sum && mul % sum == 0;

            int64_t mask = static_cast<int64_t>(mul << 32 | u << 16 | sum);

            if (!is_limit && !is_zero && mem.contains(mask)) return mem[mask];
            int cnt = is_zero ? dfs(u - 1, mul, sum, false, true) : 0;  // 什么都不填
            int limit = is_limit ? high[u] : 9;
            for (int i = is_zero; i <= limit; ++i) cnt += dfs(u - 1, mul * i, sum + i, is_limit && i == limit, false);

            if (!is_limit && !is_zero) mem[mask] = cnt;
            return cnt;
        };

        auto f = [&](int x) {
            high.clear();
            while (x > 0) high.emplace_back(x % 10), x /= 10;
            return dfs(high.size() - 1, 1, 0, true, true);
        };

        return f(r) - f(l - 1);
    }
};
void solve() {
    int n, m;
    std::cin >> n >> m;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
