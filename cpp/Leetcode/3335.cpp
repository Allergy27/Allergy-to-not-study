// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\Leetcode\3335.cpp
 * @date      2025/05/13 13:02:11
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define PII std::pair<int, int>

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

using std::array;
using std::string;
using std::vector;

class Solution {
 private:
    static constexpr int MOD = 1'000'000'007;
    static constexpr int SIZE = 26;

    using Martix = array<array<int, SIZE>, SIZE>;

    Martix mul(Martix a, Martix b) {
        Martix c{};
        for (int i = 0; i < SIZE; ++i) {
            for (int k = 0; k < SIZE; ++k) {
                if (a[i][k] == 0) continue;
                for (int j = 0; j < SIZE; ++j) (c[i][j] += (1LL * a[i][k] * b[k][j]) % MOD) %= MOD;
            }
        }
        return c;
    }

    Martix pow(Martix a, int n) {
        Martix res{};
        for (int i = 0; i < SIZE; ++i) res[i][i] = 1;
        while (n) {
            if (n & 1) res = mul(res, a);
            a = mul(a, a);
            n >>= 1;
        }
        return res;
    }

 public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> cnt(26);
        for (auto x : s) ++cnt[x - 'a'];

        Martix m{};
        array<int, SIZE> nums = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2};
        for (int i = 0; i < SIZE; ++i) {
            for (int j = i + 1; j <= i + nums[i]; ++j) m[i][j % SIZE] = 1;
        }
        Martix m_t = pow(m, t);
        int ans = 0;
        for (int i = 0; i < SIZE; ++i) {
            int tmp = 0;
            for (auto x : m_t[i]) (tmp += x) %= MOD;
            (ans += (1LL * tmp * cnt[i]) % MOD) %= MOD;
        }

        return ans;
    }
};

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int _ = 1;
    // std::cin >> _;

    auto solve = [&]() -> void {
        int n, m;
        std::cin >> n >> m;
    };

    while (_--) solve();
    std::cin >> _;
    return 0;
}
