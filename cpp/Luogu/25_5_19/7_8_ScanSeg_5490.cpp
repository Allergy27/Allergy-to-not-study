/* Copyright 2025 Allergy
 * @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\luogu\25_5_18\7_8_ScanSeg_5490.cpp
 * @date      2025/05/19 12:14:44
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define judge(x) std::cout << ((x) ? "Yes\n" : "No\n")

using ll = int64_t;
using PII = std::pair<int, int>;
using PDD = std::pair<double, double>;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

struct Info {
    ll len = 0;      // 实际被覆盖的长度
    ll raw_len = 0;  // 原始区间长度

    explicit Info() = default;
    explicit Info(int length) : raw_len(length) {}
};

Info operator+(const Info& a, const Info& b) {
    Info c;
    c.raw_len = a.raw_len + b.raw_len;
    c.len = a.len + b.len;
    return c;
}

struct SegmentTree {
    int n;
    std::vector<ll> tag;
    std::vector<Info> info;

    explicit SegmentTree(const std::vector<int>& points) : n(points.size() - 1) {
        tag.resize(4 * n);
        info.resize(4 * n);
        build(1, 0, n, points);
    }
    void add(int p, ll v) {
        tag[p] += v;
        info[p].len = (tag[p] > 0) ? info[p].raw_len : 0;
    }

    void build(int p, int l, int r, const std::vector<int>& points) {
        if (r - l == 1) {
            info[p] = Info(points[r] - points[l]);
            return;
        }
        int m = l + r >> 1;
        build(p << 1, l, m, points);
        build(p << 1 | 1, m, r, points);
        pull(p);
    }

    void pull(int p) {
        info[p] = info[p << 1] + info[p << 1 | 1];
        if (tag[p] > 0) info[p].len = info[p].raw_len;
    }

    void push(int p) {
        add(p << 1, tag[p]);
        add(p << 1 | 1, tag[p]);
        tag[p] = 0;
    }

    void range_add(int p, int l, int r, int tl, int tr, int v) {
        if (l >= tr || r <= tl) return;
        if (l >= tl && r <= tr) return add(p, v);
        push(p);
        int m = l + r >> 1;
        range_add(p << 1, l, m, tl, tr, v);
        range_add(p << 1 | 1, m, r, tl, tr, v);
        pull(p);
    }

    int all_len() const { return info[1].len; }

    void range_add(int tl, int tr, int v) { range_add(1, 0, n, tl, tr, v); }
};

struct Event {
    int x, y1, y2, flag;
};

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int _ = 1;
    // std::cin >> _;

    auto solve = [&]() -> void {
        int n, m;
        std::cin >> n;
        // 离散化y坐标
        std::vector<int> ys;
        std::vector<std::vector<int>> rectangles(n);
        for (int i = 0, x1, y1, x2, y2; i < n; ++i) {
            std::cin >> x1 >> y1 >> x2 >> y2;
            rectangles[i] = {x1, y1, x2, y2};
            ys.emplace_back(y1);
            ys.emplace_back(y2);
        }

        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());

        // 准备事件
        std::vector<Event> events;
        for (const auto& rect : rectangles) {
            int y1 = lower_bound(ys.begin(), ys.end(), rect[1]) - ys.begin();
            int y2 = lower_bound(ys.begin(), ys.end(), rect[3]) - ys.begin();
            events.push_back({rect[0], y1, y2, 1});
            events.push_back({rect[2], y1, y2, -1});
        }
        std::sort(events.begin(), events.end(), [](const Event& a, const Event& b) { return a.x < b.x; });

        // 初始化线段树
        SegmentTree st(ys);

        ll res = 0;
        int prev_x = events[0].x;
        for (const auto& event : events) {
            int dx = event.x - prev_x;
            res += 1LL * dx * st.all_len();
            st.range_add(event.y1, event.y2, event.flag);
            prev_x = event.x;
        }
        std::cout << res << ln;
    };

    while (_--) solve();
    std::cout << std::endl;
    std::cin >> _;
    return 0;
}



