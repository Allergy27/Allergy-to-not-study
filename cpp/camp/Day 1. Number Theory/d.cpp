// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\camp\Day 1. Number Theory\d.cpp
 * @date      2024/11/22 19:18:25
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int INF = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    if (m == 1) {
        cout << n << ln;
        return;
    }
    // 分解 m 的质因数
    int lim = ceil(sqrt(m));
    vector<int> factor;
    vector<bool> is_prime(lim + 1, true);
    for (int i = 2; i * i <= m; ++i) {
        if (is_prime[i]) {
            if (m % i == 0) factor.emplace_back(i);
            for (int j = i * i; j <= lim; j += i) {
                is_prime[j] = false;
            }
            while (m % i == 0) m /= i;
        }
    }
    if (m > 1) factor.emplace_back(m);  // 如果剩下的 m 是质数

    int s = 0, r = factor.size();
    for (int mask = 1; mask < (1 << r); ++mask) {          // 枚举所有非空子集
        int sign = __builtin_popcount(mask) % 2 ? 1 : -1;  // 奇数个因子 +1，偶数个因子 -1
        int product = 1;
        bool valid = true;
        for (int i = 0; i < r; ++i) {
            if (mask & (1 << i)) {
                if (product > n / factor[i]) {  // 防止乘积溢出
                    valid = false;
                    break;
                }
                product *= factor[i];
            }
        }
        if (valid) s += sign * (n / product);
    }

    cout << n - s << ln;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
