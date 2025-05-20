// Copyright 2025 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\CF\cf 1024 div2\d.cpp
 * @date      2025/05/11 23:19:34
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln std::endl
#define PII std::pair<int, int>

using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

int merge_sort(std::vector<int>& qwq, int l, int r) {
    if (l >= r) return 0;
    int mid = l + (r - l) / 2;

    int cnt = 0;  // 统计奇偶性
    (cnt += merge_sort(qwq, l, mid)) %= 2;
    (cnt += merge_sort(qwq, mid + 1, r)) %= 2;

    // merge
    std::vector<int> tmp(r - l + 1);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (qwq[i] <= qwq[j]) {
            tmp[k++] = qwq[i++];
        } else {
            tmp[k++] = qwq[j++];
            (cnt += mid - i + 1) %= 2;
        }
    }
    while (i <= mid) tmp[k++] = qwq[i++];
    while (j <= r) tmp[k++] = qwq[j++];
    for (i = l, k = 0; i <= r; ++i, ++k) qwq[i] = tmp[k];
    return cnt;
}

void qwq_sort(std::vector<int>& qwq) {
    int n = qwq.size();
    int now = merge_sort(qwq, 0, n - 1);
    if ((now % 2) && (n >= 2)) std::swap(qwq[n - 1], qwq[n - 2]);
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int _ = 1;
    std::cin >> _;

    auto solve = [&]() -> void {
        int n;
        std::cin >> n;
        std::vector<int> qwq(n), ans;
        for (auto& x : qwq) std::cin >> x;

        auto to = [&](int i) {
            std::swap(ans[i], ans[i + 2]);
            std::swap(ans[i + 1], ans[i + 3]);
        };

        std::vector tmp(2, std::vector<int>());
        for (int i = 0; i < n; ++i) tmp[i & 1].emplace_back(qwq[i]);
        for (int i = 0; i < 2; ++i) qwq_sort(tmp[i]);
        int cnt[] = {0, 0};

        for (int i = 0; i < n; ++i) ans.emplace_back(tmp[i & 1][cnt[i & 1]++]);
        if (ans[n - 4] > ans[n - 2]) to(n - 4);
        for (auto x : ans) std::cout << x << ' ';
        std::cout << ln;
    };

    while (_--) solve();
    std::cin >> _;
    return 0;
}
