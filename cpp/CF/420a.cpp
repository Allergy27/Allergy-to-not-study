// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\420a.cpp
 * @date      2025/01/12 23:40:28
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    std::string qwq;
    std::cin >> qwq;
    for (auto x : qwq) {
        if (x != 'A' && x != 'H' && x != 'I' && x != 'M' && x != 'O' && x != 'T' &&
            x != 'U' && x != 'V' && x != 'W' && x != 'X' && x != 'Y') {
            std::cout << "NO" << ln;
            return;
        }
    }
    for (int i = 0; i < qwq.size() / 2; i++) {
        if (qwq[i] != qwq[qwq.size() - i - 1]) {
            std::cout << "NO" << ln;
            return;
        }
    }
    std::cout << "YES" << ln;
}

signed main() {
    // std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
