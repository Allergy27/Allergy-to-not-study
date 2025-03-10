// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\winter_camp\Day 2\C++.cpp
 * @date      2025/01/14 20:55:20
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

using namespace std;

void solve() {
    int l = 1, r = 999;

    auto ask = [&](int a, int b) -> int {
        cout << "? " << a << ' ' << b << endl;
        int resp;
        cin >> resp;
        return resp;
    };

    while (r - l > 2) {
        int a = (2 * l + r) / 3;
        int b = (2 * r + l) / 3;
        int resp = ask(a, b);

        if (resp == (a + 1) * (b + 1)) {
            r = a;
        } else if (resp == a * b) {
            l = b;
        } else {
            l = a;
            r = b;
        }
    }
    if (r - l == 2) {
        if (ask(1, l + 1) == l + 1) {
            l = l + 1;
        } else {
            r = l + 1;
        }
    }
    cout << "! " << r << endl;
}
signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
