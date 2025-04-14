// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1009 div3\e.cpp
 * @date      2025/03/13 19:44:03
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution uni(0, 2);
    auto ask = [](int i, int j, int k) -> int {
        std::cout << "? " << i << " " << j << " " << k << ln;
        int tmp;
        std::cin >> tmp;
        return tmp;
    };
    int n;
    std::cin >> n;
    if (n < 0) return;
    std::vector<int> qwq(n);
    for (int i = 0; i < n; ++i) qwq[i] = i + 1;
    std::shuffle(qwq.begin(), qwq.end(), mt);
    int x = qwq[0], y = qwq[1], z = qwq[2];
    while (1) {
        int tmp = ask(x, y, z);
        if (tmp < 0) return;
        if (tmp == 0) break;
        int f = uni(mt);
        if (f == 0)
            x = tmp;
        else if (f == 1)
            y = tmp;
        else
            z = tmp;
    }
    std::cout << "! " << x << " " << y << " " << z << ln;
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
