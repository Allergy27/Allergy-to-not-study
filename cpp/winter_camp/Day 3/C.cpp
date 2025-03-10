// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\winter_camp\Day 3\C.cpp
 * @date      2025/01/15 19:02:43
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

std::vector<int> qwq;

bool check(int x) {
    while (x) {
        if (x % 10 > 1) return false;
        x /= 10;
    }
    return true;
}

bool find(int n) {
    if (n == 1) return true;
    bool ans = false;
    for (auto x : qwq) {
        if (n % x == 0) {
            ans |= find(n / x);
        }
    }
    return ans;
}

void solve() {
    for (int i = 2; i <= 100005; ++i)
        if (check(i)) qwq.push_back(i);
    std::vector<int> qwq = {0, 1, 10, 11, 100, 101, 110, 111};
    int n;
    std::cin >> n;
    while (n--) {
        int tmp;
        std::cin >> tmp;
        if (find(tmp))
            std::cout << "YES" << ln;
        else
            std::cout << "NO" << ln;
    }
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
