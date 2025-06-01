/* Copyright 2025 Allergy
 * @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\25_5_18\7_8_SegmentTree_3373.cpp
 * @date      2025/05/18 19:09:24
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define judge(x) std::cout << ((x) ? "Yes\n" : "No\n")

using ll = int64_t;
using ull = int64_t;
using PII = std::pair<int, int>;
using PDD = std::pair<double, double>;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

struct Info {
    int sum = 0;
    int cnt = 1;
    explicit Info() = default;
    explicit Info(int x) : sum(x), cnt(1) {}
};
Info operator+(const Info &l, const Info &r) {
    Info c;
    c.sum = l.sum + r.sum;
    c.cnt = l.cnt + r.cnt;
    return c;
}

struct SegmentTree {
    int n, mod_p;
    std::vector<int> add_tag, mul_tag;
    std::vector<Info> info;
    explicit SegmentTree(int n_, int mod_) : n(n_), add_tag(4 * n), info(4 * n), mul_tag(4 * n, 1), mod_p(mod_) {}
    void pull(int p) { info[p] = info[p << 1] + info[p << 1 | 1]; }

    void apply_mul(int p, int v) {
        mul_tag[p] = (1LL * mul_tag[p] * v) % mod_p;
        add_tag[p] = (1LL * add_tag[p] * v) % mod_p;
        info[p].sum = (1LL * v * info[p].sum) % mod_p;
    }
    void apply_add(int p, int v) {
        (add_tag[p] += v) %= mod_p;
        (info[p].sum += (1LL * v * info[p].cnt) % mod_p) %= mod_p;
    }

    void push(int p) {
        apply_mul(p << 1, mul_tag[p]);
        apply_mul(p << 1 | 1, mul_tag[p]);
        mul_tag[p] = 1;
        apply_add(p << 1, add_tag[p]);
        apply_add(p << 1 | 1, add_tag[p]);
        add_tag[p] = 0;
    }
    Info query(int p, int l, int r, int tl, int tr) {
        if (l >= tr || r <= tl) return Info();
        if (l >= tl && r <= tr) return info[p];
        int m = (l + r) >> 1;
        push(p);
        return query(p << 1, l, m, tl, tr) + query(p << 1 | 1, m, r, tl, tr);
    }
    Info query(int tl, int tr) { return query(1, 0, n, tl, tr); }

    void range_add(int p, int l, int r, int tl, int tr, int v) {
        if (l >= tr || r <= tl) return;
        if (l >= tl && r <= tr) return apply_add(p, v);
        int m = (l + r) >> 1;
        push(p);
        range_add(p << 1, l, m, tl, tr, v);
        range_add(p << 1 | 1, m, r, tl, tr, v);
        pull(p);
    }
    void range_add(int tl, int tr, int v) { range_add(1, 0, n, tl, tr, v); }

    void range_mul(int p, int l, int r, int tl, int tr, int v) {
        if (l >= tr || r <= tl) return;
        if (l >= tl && r <= tr) return apply_mul(p, v);
        int m = (l + r) >> 1;
        push(p);
        range_mul(p << 1, l, m, tl, tr, v);
        range_mul(p << 1 | 1, m, r, tl, tr, v);
        pull(p);
    }

    void range_mul(int tl, int tr, int v) { range_mul(1, 0, n, tl, tr, v); }

    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) >> 1;
        push(p);
        if (x < m)
            modify(p << 1, l, m, x, v);
        else
            modify(p << 1 | 1, m, r, x, v);
        pull(p);
    }
    void modify(int x, const Info &v) { modify(1, 0, n, x, v); }
};

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int _ = 1;
    // std::cin >> _;

    auto solve = [&]() -> void {
        int n, m, k;
        std::cin >> n >> m >> k;
        SegmentTree qwq(n + 1, k);

        for (int i = 1; i <= n; ++i) {
            int x;
            std::cin >> x;
            qwq.modify(i, Info(x));
        }
        for (int i = 0; i < m; ++i) {
            int op, x, y;
            std::cin >> op >> x >> y;
            if (op == 1) {
                int tmp;
                std::cin >> tmp;
                qwq.range_mul(x, y + 1, tmp);
            } else if (op == 2) {
                int tmp;
                std::cin >> tmp;
                qwq.range_add(x, y + 1, tmp);
            } else if (op == 3) {
                Info res = qwq.query(x, y + 1);
                std::cout << res.sum % k << ln;
            }
        }
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
