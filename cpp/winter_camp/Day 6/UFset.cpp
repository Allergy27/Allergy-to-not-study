// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\winter_camp\Day 6\UFset.cpp
 * @date      2025/01/21 19:01:55
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

struct UFset {
    std::vector<int> fa;
    UFset(int n) : fa(n) {  // NOLINT
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
    }
    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    void merge(int x, int y) {
        int p = find(x), q = find(y);
        if (p == q) return;
        fa[p] = fa[q];
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
