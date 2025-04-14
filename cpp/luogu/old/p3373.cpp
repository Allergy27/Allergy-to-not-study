// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\p3373.cpp
 * @date      2025/03/11 20:34:05
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define int int64_t

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

template <typename T>
class SegmentTree {
    std::vector<T> tree, lazy, *data;
    int n, n4;
    void build(int tl, int tr, int p) {
        if (tl == tr) {
            tree[p] = (*data)[tl];
            return;
        }
        int mid = tl + (tr - tl) / 2;
        build(tl, mid, p << 1 | 1);
        build(mid + 1, tr, p + 1 << 1);
        tree[p] = tree[p << 1 | 1] + tree[p + 1 << 1];
    }
    void maintain(int tl, int tr, int p) {
        if (tl != tr && lazy[p]) {
            int mid = tl + (tr - tl) / 2;
            lazy[p << 1 | 1] += lazy[p];
            tree[p << 1 | 1] += lazy[p] * (mid + 1 - tl);
            lazy[p + 1 << 1] += lazy[p];
            tree[p + 1 << 1] += lazy[p] * (tr - mid);
            lazy[p] = 0;
        }
    }
    void range_add(int l, int r, T val, int tl, int tr, int p) {
        if (l <= tl && tr <= r) {
            lazy[p] += val;
            tree[p] += val * (tr - tl + 1);
            return;
        }

        maintain(tl, tr, p);

        int mid = tl + (tr - tl) / 2;

        if (l <= mid) raneg_add(l, r, val, tl, mid, p << 1 | 1);
        if (mid < r) range_add(l, r, val, mid + 1, tr, p + 1 << 1);

        tree[p] = tree[p << 1 | 1] + tree[p + 1 << 1];
    }

    T range_sum(int l, int r, int tl, int tr, int p) {
        if (l <= tl && tr <= r) return tree[p];

        T sum = 0;

        maintain(tl, tr, p);

        int mid = tl + (tr - tl) / 2;

        if (l <= mid) sum += range_sum(l, r, tl, mid, p << 1 | 1);
        if (mid + 1 < r) sum += range_sum(l, r, mid + 1, tr, p + 1 << 1);

        return sum;
    }

 public:
    explicit SegmentTree(std::vector<T> qwq) {
        n = qwq.size();
        n4 = n * 4;
        tree = std::vector<T>(n4, 0);
        lazy = std::vector<T>(n4, 0);
        data = &qwq;
        build(0, n - 1, 0);
    }
};

void solve() {}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    std::cin >> t;
    return 0;
}
