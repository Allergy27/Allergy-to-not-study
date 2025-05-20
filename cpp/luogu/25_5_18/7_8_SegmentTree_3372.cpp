/* Copyright 2025 Allergy
 * @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\25_5_18\7_8_SegmentTree_3372.cpp
 * @date      2025/05/19 11:44:29
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define judge(x) std::cout << ((x) ? "Yes\n" : "No\n")

using ll = uint64_t;
using PII = std::pair<int, int>;
using PDD = std::pair<double, double>;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

struct Info {
    ll cnt = 1;
    ll sum = 0;
    explicit Info() {}
    explicit Info(ll x_) : sum(x_), cnt(1) {}
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    c.cnt = a.cnt + b.cnt;
    c.sum = a.sum + b.sum;
    return c;
}

struct SegmentTree {
    int n;
    std::vector<ll> tag;
    std::vector<Info> info;
    explicit SegmentTree(int n_) : n(n_), tag(4 * n), info(4 * n) {}

    void pull(int p) { info[p] = info[p << 1] + info[p << 1 | 1]; }

    void add(int p, ll v) {
        tag[p] += v;
        info[p].sum += v * info[p].cnt;
    }

    void push(int p) {
        add(p << 1, tag[p]);
        add(p << 1 | 1, tag[p]);
        tag[p] = 0;
    }

    Info query(int p, int l, int r, int tl, int tr) {
        if (l >= tr || r <= tl) return Info();
        if (l >= tl && r <= tr) return info[p];
        push(p);
        int m = l + r >> 1;
        return query(p << 1, l, m, tl, tr) + query(p << 1 | 1, m, r, tl, tr);
    }

    void range_add(int p, int l, int r, int tl, int tr, ll v) {
        if (l >= tr || r <= tl) return;
        if (l >= tl && r <= tr) return add(p, v);
        push(p);
        int m = l + r >> 1;
        range_add(p << 1, l, m, tl, tr, v);
        range_add(p << 1 | 1, m, r, tl, tr, v);
        pull(p);
    }

    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        push(p);
        int m = l + r >> 1;
        if (x < m)
            modify(p << 1, l, m, x, v);
        else
            modify(p << 1 | 1, m, r, x, v);
        pull(p);
    }

    Info query(int tl, int tr) { return query(1, 0, n, tl, tr); }
    void range_add(int tl, int tr, ll v) { range_add(1, 0, n, tl, tr, v); }
    void modify(int x, const Info &v) { modify(1, 0, n, x, v); }
};

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int _ = 1;
    // std::cin >> _;

    auto solve = [&]() -> void {
        int n, m;
        std::cin >> n >> m;
        SegmentTree qwq(n + 1);
        for (int i = 1; i <= n; ++i) {
            ll x;
            std::cin >> x;
            qwq.modify(i, Info(x));
        }
        while (m--) {
            int op, x, y;
            std::cin >> op >> x >> y;
            if (op == 1) {
                ll k;
                std::cin >> k;
                qwq.range_add(x, y + 1, k);
            } else {
                std::cout << qwq.query(x, y + 1).sum << ln;
            }
        }
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}
