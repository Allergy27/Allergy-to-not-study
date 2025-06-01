// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1016 div3\d.cpp
 * @date      2025/04/08 23:18:56
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t
using ull = uint64_t;
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

std::pair<int, int> get_coords(ull d, int s) {
    if (s == 1) return {1, 1};
    int half = s / 2;
    ull m = (ull)half * half;
    int i;
    ull d_;
    if (d <= m) {
        i = 1;
        d_ = d;
    } else if (d <= 2 * m) {
        i = 2;
        d_ = d - m;
    } else if (d <= 3 * m) {
        i = 3;
        d_ = d - 2 * m;
    } else {
        i = 4;
        d_ = d - 3 * m;
    }
    auto [x_, y_] = get_coords(d_, half);
    if (i == 1) {
        return {x_, y_};
    } else if (i == 2) {
        return {x_ + half, y_ + half};
    } else if (i == 3) {
        return {x_ + half, y_};
    } else {
        return {x_, y_ + half};
    }
}

ull get_d(int x, int y, int s) {
    if (s == 1) return 1;
    int half = s / 2;
    if (x <= half && y <= half) {
        return get_d(x, y, half);
    } else if (x > half && y > half) {
        ull tmp = (ull)half * half;
        return tmp + get_d(x - half, y - half, half);
    } else if (x > half && y <= half) {
        ull tmp = (ull)half * half * 2;
        return tmp + get_d(x - half, y, half);
    } else {
        ull tmp = (ull)half * half * 3;
        return tmp + get_d(x, y - half, half);
    }
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    int s = 1 << n;
    while (m--) {
        std::string op;
        std::cin >> op;
        if (op == "->") {
            int x, y;
            std::cin >> x >> y;
            std::cout << get_d(x, y, s) << ln;
        } else {
            ull d;
            std::cin >> d;
            auto [x, y] = get_coords(d, s);
            std::cout << x << ' ' << y << ln;
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
