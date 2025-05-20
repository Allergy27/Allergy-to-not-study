// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\Atcoder\abc 405\f.cpp
 * @date      2025/05/11 12:50:19
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define PII std::pair<int, int>

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int _ = 1;
    // std::cin >> _;

    auto solve = [&]() -> void {
        struct SegmentTree {
            std::vector<std::vector<int>> tree;
            int n;

            explicit SegmentTree(const std::vector<PII>& segments) {
                n = segments.size();
                tree.resize(4 * n);
                build(0, 0, n - 1, segments);
            }

            void build(int node, int l, int r, const std::vector<PII>& segments) {
                if (l == r) {
                    tree[node].push_back(segments[l].second);
                    return;
                }
                int mid = (l + r) / 2;
                build(2 * node + 1, l, mid, segments);
                build(2 * node + 2, mid + 1, r, segments);
                merge(tree[2 * node + 1].begin(), tree[2 * node + 1].end(), tree[2 * node + 2].begin(),
                      tree[2 * node + 2].end(), back_inserter(tree[node]));
            }

            int query(int a, int b, int D) { return query(0, 0, n - 1, a, b, D - 1); }

            int query(int node, int l, int r, int a, int b, int D) {
                if (r < a || l > b) return 0;
                if (a <= l && r <= b) {
                    return upper_bound(tree[node].begin(), tree[node].end(), D) - tree[node].begin();
                }
                int mid = (l + r) / 2;
                return query(2 * node + 1, l, mid, a, b, D) + query(2 * node + 2, mid + 1, r, a, b, D);
            }
        };

        int N, M;
        std::cin >> N >> M;

        std::vector<PII> segments(M);
        for (int i = 0; i < M; ++i) {
            std::cin >> segments[i].first >> segments[i].second;
            if (segments[i].first > segments[i].second) std::swap(segments[i].first, segments[i].second);
        }

        std::sort(segments.begin(), segments.end());

        std::vector<int> sorted_A, sorted_B;
        for (const auto& seg : segments) {
            sorted_A.push_back(seg.first);
            sorted_B.push_back(seg.second);
        }

        SegmentTree st(segments);
        sort(sorted_B.begin(), sorted_B.end());

        int Q;
        std::cin >> Q;
        while (Q--) {
            int C, D;
            std::cin >> C >> D;

            if (C > D) {
                auto it_A_over_C = upper_bound(sorted_A.begin(), sorted_A.end(), C);
                int part1_A = sorted_A.end() - it_A_over_C;

                auto it_A_under_D = lower_bound(sorted_A.begin(), sorted_A.end(), D);
                int part2_A = it_A_under_D - sorted_A.begin();

                int count_A = part1_A + part2_A;

                auto it_B_over_C = upper_bound(sorted_B.begin(), sorted_B.end(), C);
                int part1_B = sorted_B.end() - it_B_over_C;

                auto it_B_under_D = lower_bound(sorted_B.begin(), sorted_B.end(), D);
                int part2_B = it_B_under_D - sorted_B.begin();

                int count_B = part1_B + part2_B;

                int count_both = part1_A + part2_B;

                std::cout << count_A + count_B - 2 * count_both << ln;
            } else {
                int L = C + 1;
                int R = D - 1;

                auto it_A_left = lower_bound(sorted_A.begin(), sorted_A.end(), L);
                auto it_A_right = upper_bound(sorted_A.begin(), sorted_A.end(), R);
                int count_A = it_A_right - it_A_left;

                auto it_B_left = lower_bound(sorted_B.begin(), sorted_B.end(), L);
                auto it_B_right = upper_bound(sorted_B.begin(), sorted_B.end(), R);
                int count_B = it_B_right - it_B_left;

                int start = upper_bound(sorted_A.begin(), sorted_A.end(), C) - sorted_A.begin();
                int count_both = 0;
                if (start <= M - 1) count_both = st.query(start, M - 1, D);

                std::cout << count_A + count_B - 2 * count_both << ln;
            }
        }
    };

    while (_--) solve();
    std::cin >> _;
    return 0;
}
